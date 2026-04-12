#include<stdio.h>
int main()
{
	int a,b,c,x,y,i=0,j=0,z,p,tot;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	if(x>=y) 
	{
		i= x-y;
		p= y;
	}
	else 
	{
		j = y-x;
		p = x;
	}
	if(a+b>2*c) z = 2*c;
	else z = a+b;
	if(a>2*c) 
		a=2*c;
	if(b>2*c)
		b=2*c;
	tot = z*p + i*a + j*b;
	printf("%d\n",tot);
	return 0;
}