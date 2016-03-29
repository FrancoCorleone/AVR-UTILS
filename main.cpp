//
//  main.cpp
//  menumaker
//
//  Created by m on 28/03/16.
//  Copyright © 2016 m. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
void addlevel(int);
string func[50];
string tabstring[50];
string texts[50];
list <int> levels;
int main(int argc, const char * argv[]) {
    string line;
    fstream myfile;
    int tabpos[50];
    int tabkeys[50][5];
    int tablast[6];
    int lastlevel = 0;
    int firstinlevel[6];
    int lastinlevel[6];
    int noOfLines = 0;
    //nt var = 0;

    myfile.open("menu_structure.txt",ios::in);
    std::cout << "Hello, World!\n";
    int i = 0;
   while(!myfile.eof())
   {
       int* k1 = new int;
       int* k2 = new int;
       int* k3 = new int;
       getline(myfile,tabstring[i]);
       tabpos[i]=tabstring[i].find('No');
       //cout<<"FOUND: "<<(int)tabstring[i].find(';')<<" ";
       if(tabstring[i].find('No')!=string::npos)
       {
           *k1 = (int)tabstring[i].find(';');
           *k2 = (int)tabstring[i].find(';',(tabstring[i].find(';')+1));
           *k3 = (int)tabstring[i].length();
           cout<<"k1 "<<*k1<<endl;
           cout<<"k2 "<<*k2<<endl;
           cout<<"k3 "<<*k3<<endl;
           func[i] = tabstring[i].substr((*k1)+2,(*k2)-(*k1)-3);
           if(tabstring[i].find('#')!=string::npos || tabstring[i].find('$')!=string::npos) texts[i] = tabstring[i].substr(*k2+2,*k3-*k2-4);
           else texts[i] = tabstring[i].substr(*k2+2,*k3-*k2);
           cout<<"FUNKCJA:"<<func[i]<<endl;
           cout<<"tekst:"<<texts[i]<<endl;
       }
       //cout<<(int)tabstring[i].find(';',(int)tabstring[i].find(';')+1)<<" ";
       //cout<<(int)tabstring[i].length();
       //cout<<" "<< tabstring[i]<<endl;
       //cout<<func[i]<<endl;
       i++;
       delete k1;
       delete k2;
       delete k3;
   }
    myfile.close();
    noOfLines = i-1;
    for(int i=0; i<noOfLines+1;i++)
    {
        cout<<"POSITION:"<<i<<"  "<<tabpos[i]<<endl;
    }
    tablast[1] = noOfLines;
    firstinlevel[2] = 0;
    firstinlevel[3] = 0;
    firstinlevel[4] = 0;
    firstinlevel[5] = 0;
    //pierwszy obieg w gore
    tabkeys[0][2] = 1;
    for( int i = 1 ; i<noOfLines+1 ; i++)
    {
        tabkeys[i][3] = lastinlevel[tabpos[i]-1];
        tabkeys[i][4] = i;
        if(tabpos[i]>lastlevel)
        {
            firstinlevel[tabpos[i]] = i;
            lastinlevel[tabpos[i]] = i;
            lastinlevel[lastlevel] = i-1;
            
            addlevel(lastlevel);
            lastlevel = tabpos[i];
        }
        else if(tabpos[i] == lastlevel)
        {
            
            lastinlevel[tabpos[i]] = i;
            tabkeys[i-1][1] = i;
            tabkeys[i][0] = i-1;
            lastlevel = tabpos[i];
        }
        else if(tabpos[i]<lastlevel)
        {
            tabkeys[lastinlevel[tabpos[i]]][1]= i;
            tabkeys[i][0] = lastinlevel[tabpos[i]];
            lastinlevel[tabpos[i]] = i;
            addlevel(lastlevel);
            for(auto itr = levels.begin();itr!=levels.end();++itr)
            {
                if(tabpos[i]<(*itr))
                {
                    tabkeys[firstinlevel[*itr]][0] = lastinlevel[*itr];
                    tabkeys[lastinlevel[*itr]][1] = firstinlevel[*itr];
                    itr = levels.erase(itr);
                    itr--;
                }
            }
            lastlevel = tabpos[i];
        }
        
        else if(tabpos[i] == string::npos)
        {
            tabkeys[1][0] = noOfLines;
            tabkeys[noOfLines][1] = 1;
        }
        
        if(tabpos[i+1] <= tabpos [i])
        {
            tabkeys[i][2] = i;
        }
        if(tabpos[i+1]>tabpos[i])
        {
            tabkeys[i][2] = i+1;
        }
        


    }
        for(int i = 0 ; i<noOfLines+1 ; i++)
    {
        if(tabstring[i].find('#')!=string::npos)
        {
            tabkeys[i][0]=i;
            tabkeys[i][1]=i;
            tabkeys[i][2]=i+1;
        }
        if(tabstring[i].find('$')!=string::npos)
        {
            tabkeys[i][0]=i;
            tabkeys[i][1]=i;
            tabkeys[i][2]=i;
            tabkeys[i][3]=i;
            tabkeys[i][4]=i;
        }
            
    }
    
    fstream outputf;
    outputf.open("menu.h", ios::out);
    outputf<<"#include<iostream>\n\n";
    outputf<<"#define E_UP 0\n#define E_DOWN 1\n#define E_OK 2\n#define E_ESC 3\n#define E_IDLE 4\n\n";
    outputf<<"volatile uint8_t current_menu = 0\n";
    outputf<<"volatile uint8_t menu_event = E_IDLE\n\n";
    outputf<<"void change_menu();\n\n";
    
    for(int i=0;i<noOfLines;i++)
    {
        outputf<<"void "<<func[i]<<"(uint8_t);\n";
    }
    outputf<<"\n\n";
    outputf<<"typedef struct\n";
    outputf<<"{\n";
    outputf<<"uint8_t next_state[5];\n";
    outputf<<"void(*callback)(uint8_t event);\n";
    outputf<<"char* first_line;\n";
    outputf<<"}menu_item;\n\n";
    
    outputf<<"const menu_item menu[]=\n";
    outputf<<"{\n";
    for(int i=0;i<noOfLines;i++)
    {
        outputf<<"\t";
        for(int j=1;j<tabpos[i];j++)outputf<<"\t";
        outputf<<"{"<<"{";
        for(int k=0;k<5;k++)
        {
            outputf<<tabkeys[i][k];
            if(k<4)outputf<<",";
        }
        outputf<<"},"<<func[i]<<","<<"\""<<texts[i]<<"\"},\n";
    }
    outputf<<"};";
    outputf.close();
    fstream cppfile;
    cppfile.open("menu.cpp",ios::out|ios::trunc);
    cppfile<<"#include<iostream>\n";
    cppfile<<"#include<menu.h>\n\n";
    
    cppfile<<"void change_menu()\n{\n";
    cppfile<<"\tcurrent_menu=menu[current_menu].next_state[menu_event];\n";
    cppfile<<"\tmenu[current_menu].callback(menu_event);\n";
    cppfile<<"\t//LCD1Line(menu[current_menu].first_line); //USE YOUR LCD LIBRARY \n";
    cppfile<<"\tmenu_event = E_IDLE;\n";
    cppfile<<"}\n";
    for(int i = 0;i<noOfLines;i++)
    {
        cppfile<<"void "<< func[i] << "(uint8_t event)\n";
        cppfile<<"{\n\n}\n\n";
    }
    cppfile.close();
    return 0;
}
void addlevel(int l)
{
    levels.push_back(l);
}
