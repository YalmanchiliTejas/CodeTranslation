#include<stdio.h>
int func(int n)
{
	int fee;
	fee=n*800-(n/15)*200;
	return fee;
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",func(x));
	return 0;
}
