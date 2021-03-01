#include<reg51.h>
#include<string.h>

sbit light_01 = P1^0;
sbit light_02 = P1^1;
sbit light_03 = P1^2;
sbit light_04 = P1^3;

sbit motor_1_pin01 = P0^0;
sbit motor_1_pin02 = P0^1;

sbit motor_2_pin01 = P0^2;
sbit motor_2_pin02 = P0^3;

sbit motor_3_pin01 = P2^0;
sbit motor_3_pin02 = P2^1;

sbit motor_4_pin01 = P2^2;
sbit motor_4_pin02 = P2^3;




void Delay()
{
	int count =0;

		while(count != 20834)
	{
	TMOD = 0x01;
	TH0 = 0xF8;
	TL0 = 0xCC;
	TR0 = 1;
	while(!TF0);
	TR0 =0;
	TF0=0;
	count ++;
	}
}

#include <string.h>

#define txBufferSize 20

volatile char txBuffer[txBufferSize];
volatile char txBufferIndex;


void Ext_int_Init()
{
EA = 1; /* Enable global interrupt */
ES = 1; /* Enable Ext. interrupt0 */
}

void UART_Init()
{
TMOD = 0x20; /* Timer 1, 8-bit auto reload mode */
TH1 = 0xFD; /* Load value for 9600 baud rate */
SCON = 0x50; /* Mode 1, reception enable */
TR1 = 1; /* Start timer 1 */
}

void Serial_ISR() interrupt 4
{
if(TI==1){
if(txBuffer[txBufferIndex]!=0)
SBUF = txBuffer[txBufferIndex++];
TI = 0; /* Clear TI flag */
}
if(RI==1){
P1 = SBUF;
RI = 0; /* Clear RI flag */
}
}


void write_to_buffer(char *str){
char i;
memset(txBuffer,0,txBufferSize);
for(i=0;str[i]!=0 && i<txBufferSize;i++){
txBuffer[i] = str[i];
}
txBuffer[19] = 0;
SBUF = txBuffer[0];
txBufferIndex = 1;
}
void main()
{
		P1 = 0x00; /* Make P1 output */
Ext_int_Init(); /* Call Ext. interrupt initialize */
UART_Init();
write_to_buffer("start the program");
		
		while(1)

	{
	
		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 0;
		motor_3_pin01 = 0;
		motor_3_pin02 = 0;
		motor_4_pin01 = 0;
		motor_4_pin02 = 0;
		light_01 =0;
		light_02 =0;
		light_03 =0;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 0;
		motor_3_pin01 = 0;
		motor_3_pin02 = 0;
		motor_4_pin01 = 0;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =0;
		light_03 =0;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 1;
		motor_3_pin01 = 0;
		motor_3_pin02 = 0;
		motor_4_pin01 = 0;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =0;
		light_03 =0;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 1;
		motor_3_pin01 = 0;
		motor_3_pin02 = 0;
		motor_4_pin01 = 0;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =1;
		light_03 =0;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 1;
		motor_3_pin01 = 0;
		motor_3_pin02 = 1;
		motor_4_pin01 = 0;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =1;
		light_03 =0;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 1;
		motor_3_pin01 = 0;
		motor_3_pin02 = 1;
		motor_4_pin01 = 0;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =1;
		light_03 =1;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 1;
		motor_3_pin01 = 0;
		motor_3_pin02 = 1;
		motor_4_pin01 = 1;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =1;
		light_03 =1;
		light_04 =0;
		Delay();

		motor_1_pin01 = 0;
		motor_1_pin02 = 1;
		motor_2_pin01 = 0;
		motor_2_pin02 = 1;
		motor_3_pin01 = 0;
		motor_3_pin02 = 1;
		motor_4_pin01 = 1;
		motor_4_pin02 = 0;
		light_01 =1;
		light_02 =1;
		light_03 =1;
		light_04 =1;
		Delay();
	}
}



