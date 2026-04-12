#include<bits/stdc++.h>

using namespace std;

long long a,b,c;
long long x,y,tmpx,tmpy;
long long ans,ans2;

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&x,&y);
	tmpx=x,tmpy=y;
	
	while(x&&y)
	{
		if(a+b<c*2&&x&&y)
		{
			ans+=(a+b);
			x--;
			y--;
		}
		else if(a+b==c*2&&x&&y)
		{
			ans+=c*2;
			x--;
			y--;
		}
		else
		{
			ans+=c*2;
			x--;
			y--;
		}
	}
	
	ans=ans+(x*a)+(y*b);
	ans2=max(tmpx,tmpy)*2;
	
	cout<<min(ans,ans2*c);	
	return 0;
}