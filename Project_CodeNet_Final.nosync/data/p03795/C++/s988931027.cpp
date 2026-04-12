#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s=0,d=0,f=0,g,h,i,j;
	scanf("%d",&a);
	s=a/15;
	d=a*800;
	f=s*200;
	d=d-f;
	printf("%d\n",d);
	return 0;
}