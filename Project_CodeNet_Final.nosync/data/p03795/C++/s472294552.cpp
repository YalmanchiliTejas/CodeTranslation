#include<stdio.h>
int main(void)
{
	int n,s,d,f;
	scanf("%d",&n);
	s=n/15;
	d=n*800;
	f=s*200;
	d=d-f;
	printf("%d\n",d);
	return 0;
}