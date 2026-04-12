
#include<stdio.h>
int main(void)
{ 
	int r,g,b,a,c,d,e,f;
	scanf("%d",&r);
	scanf("%d",&g);
	scanf("%d",&b);
	a=r*100;
	c=g*10;
	d=b;
	e=a+c+d;
	if(e%4==0){
	printf("YES\n");
	}
	else {
	printf("NO\n");
	}
	return 0;
}