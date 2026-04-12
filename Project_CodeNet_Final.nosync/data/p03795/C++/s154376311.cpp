#include<stdio.h>
int main(void)
{
	int N,x,y,i,o;
	scanf("%d",&N);
	x=N*800;
	o=N/15;
	y=o*200;
	i=x-y;
	printf("%d\n",i);
	return 0;
}