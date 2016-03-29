#include<iostream>

#define E_UP 0
#define E_DOWN 1
#define E_OK 2
#define E_ESC 3
#define E_IDLE 4

volatile uint8_t current_menu = 0
volatile uint8_t menu_event = E_IDLE

void change_menu();

void callback1(uint8_t);
void callback2(uint8_t);
void callback3(uint8_t);
void callback4(uint8_t);
void callback5(uint8_t);
void callback6(uint8_t);
void callback7(uint8_t);
void callback8(uint8_t);
void callback9(uint8_t);
void callback10(uint8_t);
void callback11(uint8_t);
void callback12(uint8_t);
void callback13(uint8_t);
void callback14(uint8_t);
void callback15(uint8_t);
void callback16(uint8_t);
void callback17(uint8_t);
void callback18(uint8_t);
void callback19(uint8_t);
void callback20(uint8_t);
void callback21(uint8_t);
void callback22(uint8_t);
void callback23(uint8_t);
void callback24(uint8_t);
void callback25(uint8_t);
void callback26(uint8_t);
void callback27(uint8_t);
void callback28(uint8_t);
void callback29(uint8_t);
void callback30(uint8_t);
void callback25(uint8_t);
void callback26(uint8_t);
void callback27(uint8_t);
void callback28(uint8_t);


typedef struct
{
uint8_t next_state[5];
void(*callback)(uint8_t event);
char* first_line;
}menu_item;

const menu_item menu[]=
{
	{{0,0,1,0,0},callback1,"sys nawadniania"},
	{{32,10,2,0,1},callback2,"wybierz tryb"},
		{{4,4,3,1,2},callback3,"automatyczny"},
			{{3,3,3,2,3},callback4,"wybr auto"},
		{{2,2,5,1,4},callback5,"manualny"},
			{{5,5,6,4,5},callback6,"wybor strefy"},
				{{8,8,7,5,6},callback7,"wlacz strefe"},
					{{7,7,7,7,7},callback8,"strefa dziala"},
				{{6,6,9,5,8},callback9,"wylacz strefe"},
					{{9,9,9,9,9},callback10,"strefa wylaczona"},
	{{1,23,11,0,10},callback11,"Konf stref"},
		{{11,11,12,10,11},callback12,"Wybor strefy"},
			{{17,17,13,11,12},callback13,"ON/OFF"},
				{{15,15,14,12,13},callback14,"Wlacz strefe"},
					{{14,14,14,14,14},callback15,"Strefa wlaczona"},
				{{13,13,16,12,15},callback16,"wylacz strefe"},
					{{16,16,16,16,16},callback17,"strefa wylaczona"},
			{{12,12,18,11,17},callback18,"Czas działania"},
				{{18,18,19,17,18},callback19,"Godzina start"},
				{{19,19,20,17,19},callback20,"minuta start"},
				{{20,20,21,17,20},callback21,"godzina stop"},
				{{21,21,22,17,21},callback22,"minuta stop;"},
				{{22,22,22,22,22},callback23,"zapisano"},
	{{10,30,24,0,23},callback24,"Konf daty"},
		{{24,24,25,23,24},callback25,"Ustaw godziny"},
		{{25,25,26,23,25},callback26,"Ustaw minuty"},
		{{26,26,27,23,26},callback27,"Ustaw dzien"},
		{{27,27,28,23,27},callback28,"Ustaw miesiac"},
		{{28,28,29,23,28},callback29,"Ustaw rok"},
		{{29,29,29,29,29},callback30,"zapisano"},
	{{23,32,31,0,30},callback25,"Version"},
		{{31,31,31,30,31},callback26,"display version"},
	{{30,1,33,0,32},callback27,"Autor"},
		{{33,33,33,32,33},callback28,"display autor"},
};