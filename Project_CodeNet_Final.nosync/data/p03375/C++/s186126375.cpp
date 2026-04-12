#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn=3e3+15; 
ll n,mod;
ll g[maxn][maxn],c[maxn][maxn];
ll mul(ll a,ll b,ll p)
{
	ll r=0;
	for (;b;b>>=1,a=(a+a)%p) if (b&1) r=(r+a)%p;
	return r;
}
ll qpow(ll a,ll b,ll p)
{
	ll r=1;
	for (;b;b>>=1,a=mul(a,a,p)) if (b&1) r=mul(r,a,p);
	return r;
}
int main()
{
	scanf("%lld%lld",&n,&mod);	
	for (int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (int i=0;i<=n;i++)
	{
		g[i][0]=1;
		for (int j=1;j<=i;j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1)%mod)%mod;	
	}
	ll ans=0;
	for (int i=0;i<=n;i++)
	{
		ll k=c[n][i];
		if (i&1) k=(mod-k)%mod;
		ll x=qpow(2,n-i,mod-1);//欧拉定理，注意模数
		x=qpow(2,x,mod);
		ll kind=qpow(2,n-i,mod);
		ll cnt=0,y=1;
		for (int j=0;j<=i;j++)
		{
			cnt=(cnt+(g[i][j]*y%mod))%mod;
			y=kind*y%mod;
		} 
		ans=(ans+(k*cnt%mod*x%mod))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}