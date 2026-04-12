#include<iostream>
using namespace std;
long ans;
long cnt[55],p[55];
void dfs(long n,long x)
{
	if(n==0)
	{
		if(x>0)ans++;
		return;
	}
	if(x<=1)return;
	else if(x<=1+cnt[n-1])
	{
		dfs(n-1,x-1);
	}
	else if(x==2+cnt[n-1])
	{
		ans+=p[n-1]+1;
		return;
	}
	else if(x<=cnt[n-1]*2+2)
	{
		ans+=p[n-1]+1;
		dfs(n-1,x-cnt[n-1]-2);
		return;
	}
	else
	{
		ans+=p[n-1]*2+1;
		return;
	}
}
main()
{
	long n,x;cin>>n>>x;
	p[0]=cnt[0]=1;
	for(int i=1;i<=50;i++)
	{
		p[i]=p[i-1]*2+1;
		cnt[i]=cnt[i-1]*2+3;
	}
	dfs(n,x);
	cout<<ans<<endl;
}