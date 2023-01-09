/*
 * GccApplication6.c
 *
 * Created: 2022-12-20 오전 9:27:34
 * Author : 7
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000L

int main(void)
{
	char pattern = 0b00000001;
	DDRD =0x00; //입력
	DDRF =0xff;
	DDRB =0xff;
	
	PORTF = 0xff;
	PORTB = 0x01;

    while (1) 
    {
		if(((PIND &0b00000010)>>1)==0){
			pattern=(pattern<<1);
			if(pattern==0b00000000)
				pattern=0b00000001;
			_delay_ms(5000);
    }
		if(((PIND &0b00000100)>>2)==0){
			pattern=(pattern>>1);
			if(pattern==0b00000000)
				pattern=0b10000000;
			_delay_ms(5000);
		}
		PORTB=pattern;
	}
	return 0;
}

