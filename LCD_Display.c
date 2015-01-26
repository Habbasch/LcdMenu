/*
 * LCD_Display.c
 *
 * Created: 19.01.2015 18:05:24
 *  Author: Jan
 */ 


#include <avr/io.h>
#include "Display.h"

int main(void)
{
	lcd_init();
	cur_off();
	blink_off();

	sendString(5,0,"Hallo Werner");
	
    while(1)
    {
        //TODO:: Please write your application code 
		
		
    }
}
