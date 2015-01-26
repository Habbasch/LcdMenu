//*****************************************************************************
// Programm:
//
// Dateinname:		    declaration.h
// Version:			    1.0
// Autor:			    Joel Grepper & Jan Leuenberger
//
// Verwendungszweck:	uP-Schulung
//
// Beschreibung:
// Beinhaltet Konstanten und Funktionsdeklarationen
//
//
// Entwicklungsablauf:
// Ver: Datum:	Autor:   Entwicklungsschritt:                         Zeit:
// 1.0  21.12.14  JGr    Programmnotwendige	Konstanten hinzugefügt	  50    Min.
// 1.0  26.12.14  JGr    Ganzes Programm erstellt				      20   Min.
//
//										Totalzeit: 70 Min.
//
// Copyright: GIBZ
//*****************************************************************************

#ifndef F_CPU
#define F_CPU 8000000UL		//uC specific clock = 8MHz
#endif


#ifndef DECLARATION_H_
#define DECLARATION_H_

/*		Constants		*/
#define LCD_LINE         0x40

#define	LCD	PORTA		// Output Port for LCD
#define	LCD_D DDRA		// Data Direction Port for LCD

//	+---+---+---+---+---+
//	|PA0+PA2|PA4|PA6|VTG|
//	+---+---+---+---+---+ PORTA
//	|PA1|PA3|PA5|PA7|GND|
//	+---+---+---+---+---+

//Shortcut pins
#define LCD_DATA      PA0	//Data
#define LCD_RS        PA4	//RS
#define LCD_EN        PA5	//Enable

/*	Type Definitions	*/
typedef unsigned char byte;

/* Globals */
byte	LCD_Shdw;

/////////////////////////////////lcd_init/////////////////////////////
//
//	Name 		:	lcd_init				Creator		:	JG
//	Input		:	-						Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sends Input Byte as Command to LCD
//
///

void lcd_init();

/////////////////////////////////lcd_command//////////////////////////
//
//	Name 		:	lcd_command				Creator		:	JG
//	Input		:	byte data				Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sends Input Byte as Command to LCD
//
///

void lcd_command(byte data);

/////////////////////////////////lcd_data/////////////////////////////
//
//	Name 		:	lcd_data				Creator		:	JG
//	Input		:	byte data				Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sends Input Byte as Character to LCD
//
///

void lcd_data(byte data);

/////////////////////////////////lcd_enable///////////////////////////
//
//	Name 		:	lcd_enable				Creator		:	JG
//	Input		:	-						Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sets enable bit for a timeframe of 5us
//
///

void lcd_enable();

/////////////////////////////////lcd_out/////////////////////////////
//
//	Name 		:	lcd_out				Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sends low nibble of byte to LCD
//
///

void lcd_out(byte data);

/////////////////////////////////lcd_clear/////////////////////////////
//
//	Name 		:	lcd_clear				Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Clears display screen
//
///

void lcd_clear();

/////////////////////////////////lcd_setPos/////////////////////////////
//
//	Name 		:	lcd_setPos			Creator		:	JG
//	Input		:	byte X				Last Modify	:	14.12.2014
//					byte Y
//	Output		:	-
//	Purpose	:
//	Gets the X and Y coordinates and sets Cursor to the according position
//
///

void lcd_setPos(byte x, byte y);

/////////////////////////////////lcd_main/////////////////////////////
//
//	Name 		:	lcd_out				Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Gets LCD-Settings and sends it to the LCD
//
///

void lcd_main();

/////////////////////////////////blink_on/////////////////////////////
//
//	Name 		:	blink_on			Creator		:	JG
//	Input		:	-					Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//  Sets cursor blinking on
//
///

void blink_on();

/////////////////////////////////blink_off/////////////////////////////
//
//	Name 		:	blink_off			Creator		:	JG
//	Input		:	-					Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sets cursor blinking off
//
///

void blink_off();

/////////////////////////////////cur_home/////////////////////////////
//
//	Name 		:	cur_home			Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sends cursor to home position
//
///

void cur_home();

/////////////////////////////////cur_on/////////////////////////////
//
//	Name 		:	cur_on				Creator		:	JG
//	Input		:	-					Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sets cursor on
//
///

void cur_on();

/////////////////////////////////lcd_char/////////////////////////////
//
//	Name 		:	lcd_char			Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Sends out the data as single character
//
///

void lcd_char(byte data);

/////////////////////////////////lcd_str/////////////////////////////
//
//	Name 		:	lcd_str				Creator		:	JG
//	Input		:	byte *text			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Gets the reference and sends characters one by one
//
///

void lcd_str(char *text);

/////////////////////////////////lcd_hex/////////////////////////////
//
//	Name 		:	lcd_hex				Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Converts hexadecimal into the right ASCII character
//
///

void lcd_hex(byte data);

/////////////////////////////////lcd_number/////////////////////////////
//
//	Name 		:	lcd_number			Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Converts byte to decimal characters
//
///
void lcd_number(byte data);

/////////////////////////////////lcd_number/////////////////////////////
//
//	Name 		:	lcd_number			Creator		:	JG
//	Input		:	byte data			Last Modify	:	14.12.2014
//	Output		:	-
//	Purpose	:
//	Writes a String at the target position
//
///
void sendString(byte XPosition, byte YPosition, char *Text);



#endif /* DECLARATION_H_ */