#include<stdio.h>

int main()
{
	int a,b,c,x,y;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	int s=0;
	if(a+b<2*c)
		s+=x*a+b*y;
	else
	{
		if(x>y)
		{
			if(a<2*c)
				s+=y*2*c+(x-y)*a;
			else
				s+=x*2*c;	
		}
		else
		{
			if(b<2*c)
				s+=x*2*c+(y-x)*b;
			else
				s+=y*2*c;							
		}
	}
	printf("%d\n",s);
	return 0;
}