#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	long long a,b,c,x,y,r=0;
	long long optimal;
	scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&x,&y);
	if(2*c<=a+b)
	{
		optimal=2*c;
	}
	else optimal=a+b;
	if(x<=y)
	{
		r=optimal*x;
		if(b<=2*c)
		{
			r+=b*(y-x);
		}
		else
		{
			r+=2*c*(y-x);
		}
	}
	else if(x>y)
	{
		r=optimal*y;
		if(a<=2*c)
		{
			r+=a*(x-y);
		}
		else
		{
			r+=2*c*(x-y);
		}
	}
	printf("%lld",r);
	return 0;
}
