#include<stdio.h>
int main(void)
{
	int n,x,y,count=1;
	scanf("%d",&n);
	x = n;
	y = (n/15) * 200;
	printf("%d",n*800-y);
	return 0;
}
