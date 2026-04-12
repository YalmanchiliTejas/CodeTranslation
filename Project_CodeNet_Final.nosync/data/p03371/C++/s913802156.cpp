#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long ans=0;
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	c<<=1;
	if(c<a+b)
	{
		if(c>a&&c>b)
		{
			int qaq=min(x,y);
			ans+=1ll*c*qaq;
			ans=ans+1ll*a*(x-qaq)+1ll*b*(y-qaq);
			cout<<ans<<endl;
			return 0;
		}
		if(c<=a)
		{
			ans+=1ll*c*x;
			y-=x;
			if(y>0)
				ans+=1ll*y*min(c,b);
			cout<<ans<<endl;
			return 0;
		}
		if(c<=b)
		{
			ans+=1ll*c*y;
			x-=y;
			if(x>0)
				ans+=1ll*x*min(a,c);
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<1ll*a*x+1ll*b*y;
	return 0;
}
