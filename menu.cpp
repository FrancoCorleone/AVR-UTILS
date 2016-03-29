#include<iostream>
#include<menu.h>

void change_menu()
{
	current_menu=menu[current_menu].next_state[menu_event];
	menu[current_menu].callback(menu_event);
	//LCD1Line(menu[current_menu].first_line); //USE YOUR LCD LIBRARY 
	menu_event = E_IDLE;
}
void callback1(uint8_t event)
{

}

void callback2(uint8_t event)
{

}

void callback3(uint8_t event)
{

}

void callback4(uint8_t event)
{

}

void callback5(uint8_t event)
{

}

void callback6(uint8_t event)
{

}

void callback7(uint8_t event)
{

}

void callback8(uint8_t event)
{

}

void callback9(uint8_t event)
{

}

void callback10(uint8_t event)
{

}

void callback11(uint8_t event)
{

}

void callback12(uint8_t event)
{

}

void callback13(uint8_t event)
{

}

void callback14(uint8_t event)
{

}

void callback15(uint8_t event)
{

}

void callback16(uint8_t event)
{

}

void callback17(uint8_t event)
{

}

void callback18(uint8_t event)
{

}

void callback19(uint8_t event)
{

}

void callback20(uint8_t event)
{

}

void callback21(uint8_t event)
{

}

void callback22(uint8_t event)
{

}

void callback23(uint8_t event)
{

}

void callback24(uint8_t event)
{

}

void callback25(uint8_t event)
{

}

void callback26(uint8_t event)
{

}

void callback27(uint8_t event)
{

}

void callback28(uint8_t event)
{

}

void callback29(uint8_t event)
{

}

void callback30(uint8_t event)
{

}

void callback25(uint8_t event)
{

}

void callback26(uint8_t event)
{

}

void callback27(uint8_t event)
{

}

void callback28(uint8_t event)
{

}

