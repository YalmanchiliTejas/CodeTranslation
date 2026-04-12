#include<iostream>
#include<cstdio>
#include<cstring>
namespace not_mine
{
	typedef long long ll;
	const int N=55;
	const ll INF=123372036854775801ll;
	ll s[N],ans;
	int n;
	void work()
	{
		int p=0;
		for(int i=1;i<=n;s[i++]++)
			if(s[i]>s[p])p=i;
		s[p]-=n+1;
	}
	bool check()
	{
		for(int i=1;i<=n;i++)
			if(s[i]>=n)return 0;
		return 1;
	}
	ll calc(ll x)
	{
		ll ret=0;
		for(int i=1;i<=n;i++)
			if(s[i]>x)ret+=(s[i]-x)/(n+1);
		return ret;
	}
	void initialize()
	{
		ll tmp=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i),tmp+=s[i];
		ll u=INF,d=0,cnt=tmp-(ll)(n-1)*(n-1);
		for(int i=1;i<=n;i++)s[i]+=cnt;

		for(ll mid;u>d;)
		{
			mid=(u+d)>>1;
			if(calc(mid)<=cnt)u=mid;
			else d=mid+1;
		}
		ans=calc(d),cnt-=ans;
		for(int i=1;i<=n;s[i++]-=cnt)
			if(s[i]>d)s[i]-=(n+1)*((s[i]-d)/(n+1));
	}
	void solve()
	{
		initialize();
		for(;!check();ans++)
			work();
		printf("%lld\n",ans);
	}
}
int main()
{
	not_mine::solve();
	return 0;
}
