#include<stdio.h>

int main(void)
{
	int  a,b=100000,c=-1,d,i,e=0;
	while(1){
	b=100000;c=-1;e=0;
	scanf("%d",&a);
	if(a==0)
		break;
	for(i=1; i<=a; i++){
		scanf("%d",&d);
		if(c<d)
			c=d;
		if(b>d)
			b=d;
		e+=d;
	}
	
	printf("%d\n",(e-b-c)/(a-2)); 
	}
	
	return 0;
}

