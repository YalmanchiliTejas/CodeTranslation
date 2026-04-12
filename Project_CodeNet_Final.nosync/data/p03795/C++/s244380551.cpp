#include<stdio.h>
int main(void)
{
	int n,s,k;
	scanf("%d",&n);
	s=n/15;
	k=n*800-s*200;
	printf("%d\n",k);
	return 0;
}