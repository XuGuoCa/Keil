# include <reg52.h>
# define uint unsigned int

sbit LED = P0^0;
sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;

void main(){
	
	uint cnt = 0;
	uint arr[10] = {
	0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90
	};
	uint i = 0;
	
	ADDR0 = 0;
	ENLED = 0;
	ADDR1 = 0;
	ADDR2 = 0;
	ADDR3 = 1;
	
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;
	TR0 = 1;
	
	while(1){
		
		if (TF0 == 1){
			
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			cnt++;
			
			if (cnt >= 50){
				
				cnt = 0;
				P0 = arr[i];
				i++;
				
			}
			
			if (i == 10){
				i = 0;
			}
		}
	}
}