#include "led.h"
#define GPH2CON *(volatile unsigned int *)0xe0200c40
#define GPH2DAT *(volatile unsigned char *)0xe0200c44
#define GPJ2DAT  *(volatile unsigned char*)0xe0200284
#define ON 0
#define OFF 1
void init_key(){
	GPH2CON &=0xffff0000;
}
char get_key_vak()
{
	return GPH2DAT&0xffff;
}
char get_led_val()
{
	return GPJ2DAT&0xf;
}

void move_key(int j ,char val ,char vak ){        
        
        
         
        	if (val &(1<<j ))
        led_num_set(j ,ON);
        else  led_num_set(j ,OFF);
       
}
void delay1(char vak ,int k  ){
    
	while  (~(vak &(1<<k)))
	{
	 	
	 	vak = get_key_vak();
	 	if (vak &(1<<k))
		break;
	}
}