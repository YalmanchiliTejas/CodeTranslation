#include<stdio.h>
int main(void)
{
	int a,b,c,x,y;
	int i,min,min1,z;
	min=0; min1=-1;
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d",&x,&y);
	if(a+b>c*2){
		if(x<y){
			min1=y*c*2;
			z=x; y-=x; x=0;
		}
		else{
			min1=x*c*2;
			z=y; x-=y; y=0;
		}
		min=z*2*c;
	}	
	min+=x*a;
	min+=y*b;
	if(min1<min&&min1!=-1) min=min1;
	printf("%d\n",min);
}	
