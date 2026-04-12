#include<cstdio>
#include<algorithm>
using namespace std;
#define N 106
#define mod 1000000007
int dp[N][N],n,s[N],st[N],v[N],v2[N],ct,as=1;
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),v[i]=s[i];
	sort(v+1,v+n+1);
	v[0]=1;for(int i=1;i<=n;i++)if(v[i]!=v[i-1])v2[++ct]=v[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=ct;j++)if(s[i]==v2[j])st[i]=j;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	if(s[i]==1)
	{
		int su=0;
		for(int j=0;j<=ct+1;j++)su=(su+dp[i-1][j])%mod;
		as=2ll*as*su%mod;
		dp[i][0]=1;
	}
	else if(s[i-1]<=1)
	{
		for(int j=1;j<=st[i];j++)
		dp[i][j]=pw(2,s[i]-v2[j-1]+(j>1));
		dp[i][st[i]+1]=2;
		for(int j=1;j<=st[i];j++)dp[i][j]=(dp[i][j]-dp[i][j+1]+mod)%mod;
	}
	else if(s[i]<=s[i-1])
	{
		for(int j=1;j<=st[i-1]+1;j++)
		if(j>st[i])dp[i][st[i]+1]=(dp[i][st[i]+1]+2ll*dp[i-1][j])%mod;
		else dp[i][j]=dp[i-1][j];
	}
	else
	{
		for(int j=1;j<=st[i-1];j++)dp[i][j]=1ll*dp[i-1][j]*pw(2,s[i]-s[i-1])%mod;
		for(int j=st[i-1]+1;j<=st[i];j++)dp[i][j]=2ll*dp[i-1][st[i-1]+1]*pw(2,s[i]-v2[j-1])%mod;
		dp[i][st[i]+1]=2ll*dp[i-1][st[i-1]+1]%mod;
		for(int j=st[i-1]+1;j<=st[i];j++)dp[i][j]=(dp[i][j]-dp[i][j+1]+mod)%mod;
	}
	int su=0;
	for(int j=0;j<=ct+1;j++)su=(su+dp[n][j])%mod;
	as=1ll*as*su%mod;
	printf("%d\n",as);
}