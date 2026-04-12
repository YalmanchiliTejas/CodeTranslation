#include<stdio.h>
int main(void)
{
	int x,y,z,s;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	s=(x-z)/(y+z);
	printf("%d\n",s);
	return 0;
}