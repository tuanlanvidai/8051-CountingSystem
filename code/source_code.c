#include <REGX51.H>
int i=0;
unsigned char code
ma[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void delay(unsigned char t)
{
	unsigned char i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<125;j++);
	}
}

int dem()
{
	if(P3_5==0)
		{
			while(P3_5==0);
			if(P3_6==0)
				{
					while(P3_6==0);
					i++;
					if(i==10000)
						i=9999;
				}
		}
		if(P3_6==0)
			{
				while(P3_6==0);
				if(P3_5==0)
					{
						while(P3_5==0);
						i--;
						if(i<0)
							i=0;
					}
			}
			return i;
}

void lay(unsigned int dem)
	{ P1_0=P1_1=P1_2=0;
		if((dem>=1)&&(dem<5))
			{ 
				P1_2=1;
				P1_1=0;
				P1_0=0;
			}
		else if ((dem>=5)&&(dem<10))
			{ 
				P1_1=1;
				P1_2=0;
				P1_0=0;
			}
			else if (dem>=10)
				{
					P1_0=1;
					P1_2=0;
					P1_1=0;
				}
	}

	void main()
{
	unsigned int k;
	while(1)
		{
			k=dem();
			{
				lay(k);
				P3_1=1;
				P2=ma[k%10];
				delay(10);
				P2=0xff;
				P3_1=0;P3_2=1;
				P2=ma[(k%100)/10];
				delay(10);
				P2=0xff;
				P3_2=0;
				P3_3=1;
				P2=ma[(k%1000)/100];
				delay(10);
				P2=0xff;
				P3_3=0;P3_4=1;
				P2=ma[k/1000];
				delay(10);
				P2=0xff;
				P3_4=0;
			} 
		}
}