#include<bits/stdc++.h>
using namespace std;

	int a,b,c;
	long long ans,x,y,ab;

int main()
{
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(a+b>=2*c)
	{
		ab=min(x,y)*2;
		if(x>y)
			ans=min(ab*c+(x-y)*a,max(x,y)*2*c);
		else
			ans=min(ab*c+(y-x)*b,max(x,y)*2*c);
	}
	else
	{
		ans=min(x*a+y*b,max(x,y)*2*c);
	}
	printf("%d",ans);
}
