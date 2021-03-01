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

#define textsize 5

volatile char text[textsize];
volatile int
 textIndex;

void Delay()
{
	int count =0;
		while(count != 25000)
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



void Initialize_ext_int()
{
EA = 1;
ES = 1;
}

void UART_Init()
{
TMOD = 0x20
TH1 = 0xFD;
SCON = 0x50;
TR1 = 1;
}

void Serial_ISR() interrupt 4
{
if(TI==1){
if(text[textIndex]!=0)
SBUF = text[textIndex++];
TI = 0;
}
if(RI==1){
P3 = SBUF;
RI = 0;
}
}


void write_to_buffer(char *str){
int i;
memset(text,0,textsize);
for(i=0;str[i]!=0 && i<textsize;i++){
text[i] = str[i];
}
text[4] = 0;
SBUF = text[0];
textIndex = 1;
}

void main()
{

While(1)
{
P3 = 0x00;
Initialize_ext_int();
UART_Init();
write_to_buffer("PARTY");
		
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
