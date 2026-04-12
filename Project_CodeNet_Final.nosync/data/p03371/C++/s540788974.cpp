#include<bits/stdc++.h>
using namespace std;
int a,b,c,x,y;
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(a+b>c*2)
		if(x>y)
		{
			if(a<c*2)
				printf("%d",2*c*y+(x-y)*a);
			else
				printf("%d",2*c*x);
		}
		else
		{
			if(b<c*2)
				printf("%d",2*c*x+(y-x)*b);
			else
				printf("%d",c*2*y);
		}
	else
		printf("%d",a*x+b*y);
	return 0;
}