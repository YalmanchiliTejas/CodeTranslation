#include<bits/stdc++.h>
using namespace std;
inline long long ksm(long long b,long long n,long long mod)
{
	long long ans=1;
	while(n)
	{
		if(n%2!=0)
			ans=ans*b%mod;
		b=b*b%mod;
		n>>=1;
	}
	return ans;
}
long long c[3005][3005];
long long g[3005][3005];
int main()
{
	long long n,mod,k,kind,x,cnt,y,i,j,ans=0;
	cin>>n>>mod;
	for(i=1;i<=n;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(i=0;i<=n;i++)
	{
		g[i][0]=1;
		for(j=1;j<=i;j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1)%mod)%mod;
	}
	for(i=0;i<=n;i++)
	{
		k=c[n][i];
		if(i&1)
			k=(mod-k)%mod;
		kind=ksm(2,n-i,mod);
		x=ksm(2,n-i,mod-1);
		x=ksm(2,x,mod);
		cnt=0,y=1;
		for(j=0;j<=i;j++)
		{
			cnt=(cnt+(g[i][j]*y%mod))%mod;
			y=kind*y%mod;
		}
		ans=(ans+k*cnt%mod*x%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}