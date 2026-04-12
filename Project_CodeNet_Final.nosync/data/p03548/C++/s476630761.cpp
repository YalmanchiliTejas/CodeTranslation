#include<stdio.h>
int main()
{
	int X, Y, Z, i;
	scanf("%d %d %d",&X,&Y,&Z);
	i = (X - Z) / ( Y + Z);
	printf("%d\n",i);
}