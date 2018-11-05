#include <LPC21xx.H>
#define PRESCALE 12000
void DELAY(unsigned int);
void initTimer0(void);
void count(void);
// a, b, c, .....g,dp -- 0,1,2,....,6,7
//d1,d2,d3,d4 -- 8,9,10,11
int main()
{	
	int i;
	int b[4] = {256,512,1024,2048};
	IODIR0 = 0xfff;
	initTimer0();
	for(i = 0; i<=3;i++)
	{
	IOSET0 = b[i];
	count();
	IOCLR0 = b[i];
	}
}
void count(void)
{
	int i;
	int a[16] = {63,6,91,79,102,109,125,7,127,111,119,124, 57, 94, 121, 113};
	for (i = 0 ; i<=15;i++)
	{
		IOSET0 |= a[i];
		DELAY(500);
		IOCLR0 = a[i];
	}
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
