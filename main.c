#include <reg51.h>
#include <string.h>

//Allocating the Pins to the Lights
sbit light_01 = P1 ^ 0;
sbit light_02 = P1 ^ 1;
sbit light_03 = P1 ^ 2;
sbit light_04 = P1 ^ 3;

//Allocating Pins to Motor 01
sbit motor_1_pin01 = P0 ^ 0;
sbit motor_1_pin02 = P0 ^ 1;

//Allocating Pins to Motor 02
sbit motor_2_pin01 = P0 ^ 2;
sbit motor_2_pin02 = P0 ^ 3;

//Allocating Pins to Motor 03
sbit motor_3_pin01 = P2 ^ 0;
sbit motor_3_pin02 = P2 ^ 1;

//Allocating Pins to Motor 04
sbit motor_4_pin01 = P2 ^ 2;
sbit motor_4_pin02 = P2 ^ 3;

#define textsize 5

volatile char text[textsize];
volatile int
	textIndex;

void Delay()
{
	int count = 0;
	while (count != 25000)
	{
		TMOD = 0x01;
		TH0 = 0xF8;
		TL0 = 0xCC;
		TR0 = 1;
		while (!TF0)
			;
		TR0 = 0;
		TF0 = 0;
		count++;
	}
}

void motor_and_light_status(int s_motor_1_pin01, int s_motor_1_pin02, int s_motor_2_pin01, int s_motor_2_pin02, int s_motor_3_pin01, int s_motor_3_pin02, int s_motor_4_pin01, int s_motor_4_pin02, int s_light_01, int s_light_02, int s_light_03, int s_light_04)
{
	motor_1_pin01 = s_motor_1_pin01;
	motor_1_pin02 = s_motor_1_pin02;
	motor_2_pin01 = s_motor_2_pin01;
	motor_2_pin02 = s_motor_2_pin02;
	motor_3_pin01 = s_motor_3_pin01;
	motor_3_pin02 = s_motor_3_pin02;
	motor_4_pin01 = s_motor_4_pin01;
	motor_4_pin02 = s_motor_4_pin02;
	light_01 = s_light_01;
	light_02 = s_light_02;
	light_03 = s_light_03;
	light_04 = s_light_04;
}

void Initialize_ext_int()
{
	EA = 1;
	ES = 1;
}

void UART_Init()
{
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;
}

void Serial_ISR() interrupt 4
{
	if (TI == 1)
	{
		if (text[textIndex] != 0)
			SBUF = text[textIndex++];
		TI = 0;
	}
	if (RI == 1)
	{
		P3 = SBUF;
		RI = 0;
	}
}

void write_to_buffer(char *str)
{
	int i;
	memset(text, 0, textsize);
	for (i = 0; str[i] != 0 && i < textsize; i++)
	{
		text[i] = str[i];
	}
	text[4] = 0;
	SBUF = text[0];
	textIndex = 1;
}

void main()
{

	while(1)
	{
		P3 = 0x00;
		Initialize_ext_int();
		UART_Init();
		motor_and_light_status(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0);
		Delay();
		motor_and_light_status(0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1);
		Delay();
		write_to_buffer("PARTY");
	}
}
