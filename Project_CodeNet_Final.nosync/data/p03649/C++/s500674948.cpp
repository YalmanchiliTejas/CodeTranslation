#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
namespace tryy
{
	typedef long long ll;
	const int N=55;
	ll s[N],ans;
	int n,ind;
	void initialize()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i);
		std::sort(s+1,s+n+1);
	}
	ll calc()
	{
//		printf("ind = %d\n",ind);
//		for(int i=1;i<=n;i++)
//			printf("%lld ",s[i]);
//		printf("\n");
		ll v=ind+(n-ind+1);
		ll x=s[ind-1],y=s[n]-n+1,d=y-x;
		if(x>=y)return 0;
//		printf(":%lld\n",(d/v)+(d%v!=0));
		return (d/v)+(d%v!=0)-1;
	}
	bool query()
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]>s[n]-n)cnt++;
		return cnt>=(n-ind+1);
	}
	void doo()
	{
		int p=0;
		for(int i=1;i<=n;i++)
			if(s[i]>s[p])p=i;
		s[p]-=n;
		for(int i=1;i<=n;i++)
			if(i!=p)s[i]++;
	}
	void run(ll x)
	{
		ll d=x*ind,siz=n-ind+1;
		for(int i=1;i<ind;i++)
			s[i]+=siz*x;
		for(int i=ind;i<=n;i++)
			s[i]-=d;
		ans+=siz*x;
		ind--;

		while(!query())doo(),ans++;

		std::sort(s+ind,s+n+1);
	}
	bool check()
	{
		for(int i=1;i<=n;i++)
			if(s[i]>=n)return 0;
		return 1;
	}
	void frun()
	{
//		for(int i=1;i<=n;i++) printf("%lld ",s[i]);
//		printf("\n");
		if(s[1]>n)
		{
			ll d=s[1]-n;
			ans+=d*n;
			for(int i=1;i<=n;i++)
				s[i]-=d;
		}
		while(!check())doo(),ans++;
	}
	void solve() 
	{
		initialize();
		ans=0;ind=n;
		while(ind>1)run(calc());
		frun();
		printf("%lld\n",ans);
	}
}
int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	tryy::solve();
	return 0;
}
