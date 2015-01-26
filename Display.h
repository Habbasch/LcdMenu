/*
 * Display.h
 *
 * Created: 19.01.2015 19:17:58
 *  Author: Jan
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_





#endif /* DISPLAY_H_ */

//*****************************************************************************
// Programm:
//
// Dateinname:		    Display.h
// Version:			    1.0
// Autor:			    Joel Grepper & Jan Leuenberger
//
// Verwendungszweck:	uP-Schulung
//
// Beschreibung:
// Beinhaltet Treiber für die Ansteuerung eines LCD Displays.
//
//
// Entwicklungsablauf:
// Ver: Datum:	Autor:  Entwicklungsschritt:                        Zeit:
// 1.0  14.12.14  JGr   LCD_Drvier uebersetzt von Assembler zu C	300 Min.
// 1.0  21.12.14  JGr   Weiter Fehlerbehebung						80	Min.
// 1.0  21.12.14  JGr   lcd_number hinzugefügt						50  Min.
// 1.0  19.01.15  JLe	sendString() hinzugefügt					10	Min.
//
//										Totalzeit: * Min.
//
// Copyright: Joel Grepper & Jan Leuenberger
//*****************************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "makros.h"
#include "declaration.h"
#include <util/delay.h>

/*		Initialisierung		*/
void lcd_init() {
	
	LCD_D = 0xFF;
	LCD = 0x00;
	
	_delay_ms(30);
	lcd_out(0b00000011);
	_delay_ms(10);

	lcd_out(0b00000011);
	_delay_ms(5);

	lcd_out(0b00000011);
	_delay_ms(5);
	
	//  Stellt LCD auf 4 Bit Kommunikation um
	lcd_out(0b00000010);
	_delay_ms(10);
	//	0   0   N   F   *   *
	lcd_command(0b00101000);
	//	0   0   0   0   0   0
	//	0   0   1   1   1   1
	lcd_command(0b00001111);
	lcd_clear();
	//	0   0   0   0   0   0
	//	0   0   0   1  I/D  S
	lcd_command(0b00000110);
	_delay_ms(50);
	
	return;

	//												* = Don't Care
	//												N = Number of Display Lines
	//												F = Character Font
	//											  	I/D = Increment Decrement(Writing Direction)
	//												S = Display Behaviour
	//											  	(1 = Cursor stays, 0 = Cursor floats with Characters)

}
void lcd_out(byte data){
	data &= 0xF0;                   // obere 4 Bit maskieren

	LCD &= ~(0xF0>>(4-LCD_DATA)); // Maske löschen
	LCD |= (data>>(4-LCD_DATA)); // Bits setzen
	lcd_enable();
	return;
}
void lcd_command(byte data) {
	
	LCD &= (0<<LCD_RS);			// RS auf 0 setzen
	lcd_out( data );			// zuerst die oberen,
	lcd_out( data<<4 );			// dann die unteren 4 Bit senden

	_delay_ms(1);
	return;
}
void lcd_data(byte data) {
	
	LCD |= (1<<LCD_RS);		// RS auf 1 setzen	
	lcd_out( data );        // zuerst die oberen,
	
	LCD |= (1<<LCD_RS);		// RS auf 1 setzen	
	lcd_out( data<<4 );     // dann die unteren 4 Bit senden	
	
	_delay_ms(1);
	return;
}
void lcd_enable(){
	LCD |= (1<<LCD_EN); // Enable auf 1 setzen
	_delay_us(5); // kurze Pause
	LCD &= (0<<LCD_EN); // Enable auf 0 setzen
	return;
}
void lcd_setPos(byte x, byte y) {
	
	byte pos;

	pos = 0x80 + LCD_LINE * y + x;

	lcd_command( pos );
	return;
}
void lcd_main() {
	lcd_command(LCD_Shdw);
	return;
}
void blink_on() {
	setBit_M(LCD_Shdw, 0x0);

	lcd_main();
	return;
}
void blink_off() {
	clrBit_M(LCD_Shdw, 1);

	lcd_main();
	return;
}
void cur_on() {
	setBit_M(LCD_Shdw, 1);

	lcd_main();
	return;
}
void cur_off() {
	
	clrBit_M(LCD_Shdw, 0);
	clrBit_M(LCD_Shdw, 1);

	lcd_main();
	return;
}
void lcd_on() {
	setBit_M(LCD_Shdw, 0);
	setBit_M(LCD_Shdw, 1);

	lcd_main();
	return;
}
void lcd_clear() {
	lcd_command(0x01);
	return;
}
void lcd_off() {
	clrBit_M(LCD_Shdw, 0);

	lcd_main();
	return;
}
void lcd_char(byte data) {
	lcd_data(data);
	return;
}
void lcd_str(char *text) {
	
	while(*text != '\0') {
		lcd_data(*text++);

	}
	return;
}
void lcd_hex(byte data) {
	byte high;
	byte low;
	nSplit(data, low, high);

	if( high >= 0x0A) {
		data = 0b01000001;
		high -= 0x0A;
		data += high;
		} else {
		data = 0b00110000;
		data += high;
	}

	lcd_data(data);
	data = 0;
	if (low >= 0x0A) {
		data = 0b01000001;
		low -= 0x0A;
		data += low;
		} else {
		data = 0b00110000;
		data += low;
	}
	lcd_data(data);
	return;
}
void lcd_number(byte data) {
	int number = 0;
	int count = 0;
	byte cache;
	while(data != 0){
		cache = data >> (count+1);
		if (cache < (data >> (count))){
			number += count * 2;
			if (count == 0){
				number++;
			}
		}
		count++;
	}
	while (number != 0){
		cache = number % 10;
		number = number/10;
		lcd_char(cache + 48);
	}
}
void cur_home() {
	lcd_command(0x02);
	return;
}
void sendString(byte XPosition, byte YPosition, char *Text){
	
	lcd_setPos(XPosition, YPosition);
	
	while(*Text != '\0'){
		lcd_data(*Text++);
	}
	
}
