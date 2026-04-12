#include<stdio.h>
int main(void)
{
	int r,g,b,i;
	scanf("%d %d %d",&r,&g,&b);
	g=g*10;
	b=g+b;
	if(b%4==0)	printf("YES\n");
	else	printf("NO\n");
	return 0;
}