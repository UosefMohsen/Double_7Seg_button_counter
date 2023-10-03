/*
* Double Seven segment.c
*
* Created: 9/29/2023 8:57:45 AM
* Author : Youssef
*/

#define F_CPU 16000000ul
#include <avr/io.h>
#include <util/delay.h>
#include "STDMACROS.h"
#include "Seven_Segment.h"


int main(void)
{
	
	
	set_bit(DDRA, 0);
	set_bit(DDRA, 1);
	set_bit(DDRA, 2);
	set_bit(DDRA, 3);
	set_bit(DDRA, 4);
	set_bit(DDRA, 5);
	set_bit(DDRA, 6);
	set_bit(DDRA, 7);
	
	clear_bit(DDRB, 0);
	clear_bit(DDRD, 2);
	
	char right = 0;
	char left = 0;
	char count = 0;
	
	SS_1D(PORTA, right);
	SS_2D(PORTA, left);
	while (1)
	{
		//Increment
		if(read_bit(PINB, 0) == 1){
			if(count < 99){
				count++;
			}
			else{
				count = 0;
			}
			right = count % 10;
			left = count / 10;
			SS_1D(PORTA, right);
			SS_2D(PORTA, left);
			while(read_bit(PINB, 0) == 1);
		}
		
		//Decrement
		if(read_bit(PIND, 6) == 1){
			if(count > 0){
				count--;
			}
			else{
				count = 99;
			}
			right = count % 10;
			left = count / 10;
			SS_1D(PORTA, right);
			SS_2D(PORTA, left);
			while(read_bit(PIND, 6) == 1);
		}
	}
		
	}
			

