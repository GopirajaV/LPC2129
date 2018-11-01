#include <LPC21xx.H>
#define PLOCK 0x00000400
#define PRESCALE 12000
void DELAY(unsigned int);
void initialize_led(void);
void initTimer0(void);
int main()
{
	initTimer0();
initialize_led();
}
void initTimer0(void)
{
	T0CCR = 0x0;
	T0PR = PRESCALE-1;
	T0TCR = 0x02;
}

void DELAY(unsigned int milliseconds)
{	
	T0TCR = 0x02;
	T0TCR= 0x01;
	while(T0TC <milliseconds);
	T0TCR = 0x00;
	T0TC = 0x00;

}
void initialize_led(void)
{	int i;
	IODIR0=0X00000FF0;
	for(i=4;i<=11;i++)
	{
	IOSET0=1<<i;
	DELAY(500);
	IOCLR0=1<<i;
	DELAY(500);
	}
}
