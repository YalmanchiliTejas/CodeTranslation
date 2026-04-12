#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,y,k;
	scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
	if((2*c)<(a+b))
	{
		if(x>y)
		{
			k=x*c*2;
			if((y*2*c+(x-y)*a)<k)
				printf("%d",y*2*c+(x-y)*a);
			else
				printf("%d",k);
		}
		else
		{
			k=y*c*2;
			if((x*2*c+(y-x)*b)<k)
				printf("%d",x*2*c+(y-x)*b);
			else
				printf("%d",k);
		}
	}
	else
		printf("%d",x*a+y*b);
	return 0;
}
