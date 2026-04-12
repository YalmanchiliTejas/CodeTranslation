#include<stdio.h>
int main(void)
{
	int N,x,y,a,b;
	scanf("%d",&N);
	x=N*800;
	a=N/15;
	y=a*200;
	b=x-y;
	printf("%d\n",b);
	return 0;
}
