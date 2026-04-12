#include<stdio.h>
int main ()
{
	int x,y,z;
	scanf("%d%d%d", &x, &y, &z);
	int o = x%(y+z);
	if (o>=z)
	{
		printf("%d",x/(y+z));
	}
	else 
	{
		printf("%d",x/(y+z)-1);
	}
	return 0;
}