#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll MOD,c[3005][3005],f[3005][3005],pw2[3005];
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
int main()
{
	scanf("%d%lld",&n,&MOD);
	c[0][0]=1;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
	{
		if(c[i][j]>=MOD)c[i][j]-=MOD;
		c[i+1][j+1]+=c[i][j];
		c[i+1][j]+=c[i][j];
	}
	pw2[0]=1;
	for(int i=1;i<=n;i++)pw2[i]=pw2[i-1]*2%(MOD-1);
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%MOD;
			f[i+1][j]=(f[i+1][j]+f[i][j]*(j+1))%MOD;
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
	{
		ll s=0,pw=quick_pow(2,n-i),v=1;
		for(int j=0;j<=i;j++,v=v*pw%MOD)s=(s+v*f[i][j])%MOD;
		if(i&1)ans-=c[n][i]*quick_pow(2,pw2[n-i])%MOD*s%MOD;
		else ans+=c[n][i]*quick_pow(2,pw2[n-i])%MOD*s%MOD;
	}
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}