#include<stdio.h>
int main(void)
{
	int n,i,w;
	scanf("%d",&n);
	i=n/15;
	i=i*200;
	n=n*800;
	w=n-i;
	printf("%d\n",w);
}	