/*	Author: mwu134
 *  Partner(s) Name: Min Chen Wu
 *	Lab Section: 22
 *	Assignment: Lab 2  Exercise 4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0x00; PORTB = 0xFF;
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */

    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char total = 0x00;
    while (1) {
	//input
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	//computation
	total = (tmpA + tmpB + tmpC) >> 2;
	PORTD = total;
	if((tmpA+tmpB+tmpC) > 140){
		PORTD = (PORTD & 0xFE) | 0x01;
	}else if(abs(tmpA - tmpB) > 80 || abs(tmpA - tmpC) > 80 || abs(tmpB - tmpC) > 80){
		PORTD = (PORTD & 0xFD) | 0x02;
	}
	

    }
    return 0;

}
