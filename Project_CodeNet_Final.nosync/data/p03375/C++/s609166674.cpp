#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll i,j,n,m,mod,res,js,ans;
ll C[3100][3100],g[3100][3100];//9000000
ll pow_mod(ll x,ll y,ll mm)
{
	ll sum=1;
	while(y)
	{
		if(y&1)
		{
			sum=sum*x%mm;
		}
		x=x*x%mm;
		y>>=1;
	}
	return sum;
}
int main()
{
	ll i,j;
	scanf("%lld%lld",&n,&mod);
	for(i=0;i<=n;i++)
	{
		C[i][0]=1;g[i][0]=1; 
		for(j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			g[i][j]=(g[i-1][j-1]+(j+1)*g[i-1][j]%mod)%mod;
		}
	}
	for(i=0;i<=n;i++)
	{
	    ll qwe=pow_mod(2,pow_mod(2,n-i,mod-1),mod);
	    ll asd=pow_mod(2,n-i,mod),zxc=1;js=0;
		for(j=0;j<=i;j++)
		{
			js=(js+g[i][j]*zxc%mod)%mod;
			zxc=zxc*asd%mod;
		}
		ans=(ans+((i&1)?mod-C[n][i]:C[n][i])*js%mod*qwe%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
} 