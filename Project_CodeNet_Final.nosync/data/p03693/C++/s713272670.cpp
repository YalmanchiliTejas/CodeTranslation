#include<stdio.h>
int main()
{
	int r,g,b,s;
	scanf("%d%d%d",&r,&g,&b);
	s=r*100+g*10+b;
	if(s%4==0)
	printf("YES") ;
	else
	printf("NO");
	return 0;
 } 