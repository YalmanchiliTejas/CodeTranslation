#include<stdio.h>
int main(void)
{
	int n,i,w;
	scanf("%d",&n);
	i=n/15;
	w=n*800-i*200;
	printf("%d\n",w);
	return 0;
}	