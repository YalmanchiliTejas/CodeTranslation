#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,sa[105],rnk[105];
ll k,h[105],s[105],f0;
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
bool cmp(int a,int b)
{
	return h[a]<h[b];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
	for(int i=1;i<=n;i++)
	{
		sa[i]=i;
		if(n!=1&&h[i]>max(h[i-1],h[i+1]))
		{
			k+=h[i]-max(h[i-1],h[i+1]);
			h[i]=max(h[i-1],h[i+1]);
		}
	}
	sort(sa+1,sa+n+1,cmp);
	for(int i=1;i<=n;i++)rnk[sa[i]]=i;
	f0=1;
	h[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(rnk[i]<rnk[i-1])f0=(f0*2+(s[rnk[i-1]]-s[rnk[i]]+MOD)*2)%MOD;
		else
		{
			for(int j=1;j<=rnk[i-1];j++)
			  s[j]=s[j]*quick_pow(2,h[i]-h[i-1])%MOD;
			for(int j=rnk[i-1]+1;j<=rnk[i];j++)
			  s[j]=(s[j-1]+f0*2*(quick_pow(2,h[i]-h[sa[j-1]])-quick_pow(2,h[i]-h[sa[j]])+MOD))%MOD;
			f0=f0*2%MOD;
		}
	}
	ll ans=s[rnk[n]]+f0;
	ans=ans%MOD*quick_pow(2,k)%MOD;
	printf("%lld\n",ans);
	return 0;
}