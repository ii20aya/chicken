#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdbool.h>
#include "macro.h"
#include "DIO.h"
#include "lcd.h"
#include "timer.h"
#include "keypad.h"
#include <avr/interrupt.h>//to use bilt in functions in interrupt
#include <stdio.h>
#include <math.h>
#include <float.h>
#define NOTPRESSED 0xff
int main(void)
{
  LCD_inti();
  BUTTON_init('d',0);
  BUTTON_init('c',0);
  BUTTON_init('a',0);
  BUZZER_init('a',2);
  
  
  int i=0;
  
  unsigned char flag=1;
  unsigned char count=0;
  unsigned char count1=0;
  unsigned char pomp=0;
  LCD_send_string("Start in");
  _delay_ms(600);
  LCD_move_cursore(2,1);
  LCD_send_string("chicken Invaders ");
  _delay_ms(1500);
  
  
  
  LCD_clear_screen();
  //LCD_send_command(0x0c); //display on cursore off
  LCD_send_command(64); //strat to point in cgram ???=?? ???? ??????? ???? ???? ???
  LCD_send_data(0x04);
  LCD_send_data(0x04);
  LCD_send_data(0x1F);
  LCD_send_data(0x1B);
  LCD_send_data(0x1F);
  LCD_send_data(0x0E);
  LCD_send_data(0x1F);
  LCD_send_data(0x1F);

  //LCD_send_command(64);// ???? ???? ?????? ????? ???
  LCD_send_data(0x0E);
  LCD_send_data(0x0E);
  LCD_send_data(0x04);
  LCD_send_data(0x1F);
  LCD_send_data(0x15);
  LCD_send_data(0x04);
  LCD_send_data(0x0A);
  LCD_send_data(0x11);
  
  
  
  
  //LCD_send_command(64); // ???? ???? ?????? ???? ????? ?? ??????? ????? ???? ??????
  LCD_send_data(0x11);
  LCD_send_data(0x0A);
  LCD_send_data(0x15);
  LCD_send_data(0x0A);
  LCD_send_data(0x11);
  LCD_send_data(0x00);
  LCD_send_data(0x11);
  LCD_send_data(0x1F);
  
  
  

  while(1){
	  //LCD_send_command(0x0c);
	  LCD_move_cursore(1,3);
	  LCD_send_string("LEVEL ONE");
	  _delay_ms(800);
	  LCD_move_cursore(2,8);
	  LCD_send_string("Ready!");
	  _delay_ms(1500);
	  LCD_clear_screen();
	  
	  LCD_move_cursore(2,1);
	  LCD_send_data(0);
	  _delay_ms(500);
	  
	  LCD_move_cursore(1,1);
	  LCD_send_data(1);
	  _delay_ms(1000);
	  
	  LCD_move_cursore(1,4);
	  LCD_send_data(1);
	  _delay_ms(1000);
	  
	  
	  LCD_move_cursore(1,9);
	  LCD_send_data(1);
	  _delay_ms(3000);
	  
	  
	  
	  ///starttttt in level oneee
	  
	  while(flag<=3){
		  
		  
		  if(BUTTON_read('d',0)==1 && pomp==0 ){ //pompppp
		  
		  
		  LCD_move_cursore(1,1);
		  LCD_send_data(2);
		  BUZZER_ON('A',2);
		  
		  _delay_ms(1000);
		  BUZZER_OFF('A',2);
		  LCD_move_cursore(1,1);
		  LCD_send_data(32);
		  _delay_ms(500);
		  flag++;
		  pomp++;
	  }
	  
	  
	  if(BUTTON_read('d',0)==1 && pomp==1){
		  
		  LCD_move_cursore(1,4);
		  LCD_send_data(2);
		  BUZZER_ON('a',2);
		  _delay_ms(1000);
		  BUZZER_OFF('a',2);
		  LCD_move_cursore(1,4);
		  LCD_send_data(32);
		  _delay_ms(500);
		  flag++;
		  pomp++;
	  }
	  
	  
	  
	  if(BUTTON_read('d',0)==1 && pomp==2){
		  LCD_move_cursore(1,9);
		  LCD_send_data(2);
		  BUZZER_ON('a',2);
		  
		  _delay_ms(1000);
		  
		  BUZZER_OFF('a',2);
		  LCD_move_cursore(1,9);
		  LCD_send_data(32);
		  _delay_ms(500);
		  LCD_clear_screen();
		  flag++;
		  
	  }
	  
	  //end of cases of pomping in level oneee
	  
	  
	  
	  if(BUTTON_read('a',0)==1 && count==0 ){  //to right
	  
	  LCD_move_cursore(2,1);
	  LCD_send_data(32);
	  LCD_move_cursore(2,2);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  
  if(BUTTON_read('a',0)==1 &&  count==1){
	  LCD_move_cursore(2,2);
	  LCD_send_data(32);
	  LCD_move_cursore(2,3);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  
  if(BUTTON_read('a',0)==1 &&  count==2){
	  LCD_move_cursore(2,3);
	  LCD_send_data(32);
	  LCD_move_cursore(2,4);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  
  if(BUTTON_read('a',0)==1 &&  count==3){
	  LCD_move_cursore(2,4);
	  LCD_send_data(32);
	  LCD_move_cursore(2,5);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  if( BUTTON_read('a',0)==1 && count==4){
	  LCD_move_cursore(2,5);
	  LCD_send_data(32);
	  LCD_move_cursore(2,6);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  if(BUTTON_read('a',0)==1 &&  count==5){
	  LCD_move_cursore(2,6);
	  LCD_send_data(32);
	  LCD_move_cursore(2,7);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  if(BUTTON_read('a',0)==1 && count==6){
	  LCD_move_cursore(2,7);
	  LCD_send_data(32);
	  LCD_move_cursore(2,8);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  if(BUTTON_read('a',0)==1 &&  count==7){
	  LCD_move_cursore(2,8);
	  LCD_send_data(32);
	  LCD_move_cursore(2,9);
	  LCD_send_data(0);
	  _delay_ms(2000);
	  count++;
  }
  
  
  
  
  
  }
  
  pomp=0;
  count=0;
  count1=0;
  flag=0;
  
  LCD_move_cursore(1,3);
  LCD_send_string("NOW .. GO to");
  _delay_ms(800);
  LCD_move_cursore(2,8);
  LCD_send_string("LEVEL TWO.");
  _delay_ms(1500);
  LCD_clear_screen();
  
  LCD_move_cursore(2,7);
  LCD_send_data(0);
  _delay_ms(1000);
  
  LCD_move_cursore(1,7);
  LCD_send_data(1);
  _delay_ms(700);
  
  LCD_move_cursore(1,5);
  LCD_send_data(1);
  _delay_ms(700);
   
   LCD_move_cursore(1,3);
   LCD_send_data(1);
   _delay_ms(700);
  
  
  LCD_move_cursore(1,1);
  LCD_send_data(1);
  _delay_ms(700);
  
  
  LCD_move_cursore(1,10);
  LCD_send_data(1);
  _delay_ms(700);
  
  LCD_move_cursore(1,14);
  LCD_send_data(1);
  _delay_ms(700);
  
  LCD_move_cursore(1,16);
  LCD_send_data(1);
  _delay_ms(700);
  
  
  
  
  //////////////////
  while(flag<=7){
    
    
    if(BUTTON_read('d',0)==1 && pomp==0 ){ //pompppp
    LCD_move_cursore(1,7);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,7);
    LCD_send_data(32);
    _delay_ms(500);
    flag++;
    pomp++;
  }
  
  
  if(BUTTON_read('d',0)==1 && pomp==1){
    
    LCD_move_cursore(1,5);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,5);
    LCD_send_data(32);
    _delay_ms(500);
    flag++;
    pomp++;
  }
  
  
  
  if(BUTTON_read('d',0)==1 && pomp==2){
    LCD_move_cursore(1,3);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,3);
    LCD_send_data(32);
    _delay_ms(500);
    
    flag++;
    pomp++;
    
  }
  
  if(BUTTON_read('d',0)==1 && pomp==3){
    LCD_move_cursore(1,1);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,1);
    LCD_send_data(32);
    _delay_ms(500);
    
    flag++;
    pomp++;
    
  }
  if(BUTTON_read('d',0)==1 && pomp==4){
    LCD_move_cursore(1,10);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,10);
    LCD_send_data(32);
    _delay_ms(500);
    
    flag++;
    pomp++;
    
  }
  if(BUTTON_read('d',0)==1 && pomp==5){
    LCD_move_cursore(1,14);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,14);
    LCD_send_data(32);
    _delay_ms(500);
    
    flag++;
    pomp++;
    
  }
  if(BUTTON_read('d',0)==1 && pomp==6){
    LCD_move_cursore(1,16);
    LCD_send_data(2);
    BUZZER_ON('a',2);
    _delay_ms(1000);
    BUZZER_OFF('a',2);
    LCD_move_cursore(1,16);
    LCD_send_data(32);
    _delay_ms(500);
    LCD_clear_screen();
    flag++;
    
    
  }
  
  
  //end of cases of pomping in level twooooo
  
  
  
  if(BUTTON_read('c',0)==1 && count1==0 ){  //to left
  
  LCD_move_cursore(2,7);
  LCD_send_data(32);
  LCD_move_cursore(2,6);
  LCD_send_data(0);
  _delay_ms(2000);
  count1++;
}


if(BUTTON_read('c',0)==1 &&  count1==1){
  LCD_move_cursore(2,6);
  LCD_send_data(32);
  LCD_move_cursore(2,5);
  LCD_send_data(0);
  _delay_ms(2000);
  count1++;
}
if(BUTTON_read('c',0)==1 &&  count1==2){
	LCD_move_cursore(2,5);
	LCD_send_data(32);
	LCD_move_cursore(2,4);
	LCD_send_data(0);
	_delay_ms(2000);
	count1++;
}


if(BUTTON_read('c',0)==1 &&  count1==3){
	LCD_move_cursore(2,4);
	LCD_send_data(32);
	LCD_move_cursore(2,3);
	LCD_send_data(0);
	_delay_ms(2000);
	count1++;
}

if( BUTTON_read('c',0)==1 && count1==4){
	LCD_move_cursore(2,3);
	LCD_send_data(32);
	LCD_move_cursore(2,2);
	LCD_send_data(0);
	_delay_ms(2000);
	count1++;
}

if(BUTTON_read('c',0)==1 &&  count1==5){
	LCD_move_cursore(2,2);
	LCD_send_data(32);
	LCD_move_cursore(2,1);
	LCD_send_data(0);
	_delay_ms(2000);
	count1++;
}


////////////end of shift left in level twooooo

//now start shift to right in level twoo

if(BUTTON_read('a',0)==1 && count==0 ){  //to right

LCD_move_cursore(2,1);
LCD_send_data(32);
LCD_move_cursore(2,2);
LCD_send_data(0);
_delay_ms(2000);
count++;
}


if(BUTTON_read('a',0)==1 &&  count==1){
  LCD_move_cursore(2,2);
  LCD_send_data(32);
  LCD_move_cursore(2,3);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}


if(BUTTON_read('a',0)==1 &&  count==2){
  LCD_move_cursore(2,3);
  LCD_send_data(32);
  LCD_move_cursore(2,4);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}


if(BUTTON_read('a',0)==1 &&  count==3){
  LCD_move_cursore(2,4);
  LCD_send_data(32);
  LCD_move_cursore(2,5);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}

if( BUTTON_read('a',0)==1 && count==4){
  LCD_move_cursore(2,5);
  LCD_send_data(32);
  LCD_move_cursore(2,6);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}

if(BUTTON_read('a',0)==1 &&  count==5){
  LCD_move_cursore(2,6);
  LCD_send_data(32);
  LCD_move_cursore(2,7);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}

if(BUTTON_read('a',0)==1 &&  count==6){
  LCD_move_cursore(2,7);
  LCD_send_data(32);
  LCD_move_cursore(2,8);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==7){
  LCD_move_cursore(2,8);
  LCD_send_data(32);
  LCD_move_cursore(2,9);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==8){
  LCD_move_cursore(2,9);
  LCD_send_data(32);
  LCD_move_cursore(2,10);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==9){
  LCD_move_cursore(2,10);
  LCD_send_data(32);
  LCD_move_cursore(2,11);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==10){
  LCD_move_cursore(2,11);
  LCD_send_data(32);
  LCD_move_cursore(2,12);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==11){
  LCD_move_cursore(2,12);
  LCD_send_data(32);
  LCD_move_cursore(2,13);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==12){
  LCD_move_cursore(2,13);
  LCD_send_data(32);
  LCD_move_cursore(2,14);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==13){
  LCD_move_cursore(2,14);
  LCD_send_data(32);
  LCD_move_cursore(2,15);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}
if(BUTTON_read('a',0)==1 &&  count==14){
  LCD_move_cursore(2,15);
  LCD_send_data(32);
  LCD_move_cursore(2,16);
  LCD_send_data(0);
  _delay_ms(2000);
  count++;
}




  }
  
  
  
  
  
  
  ////////////////////
  
  }
  }	