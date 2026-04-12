#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
const int MAXN=1e3,MOD=1e9+7;
int n,A,B,C,D;
ll fac[MAXN+10],inv[MAXN+10],cur,dp[MAXN+10][MAXN+10];

ll quickpow(ll a,ll b)
{
	ll ret=1;
	for(;b;b>>=1,a=a*a%MOD)
		if(b&1) ret=ret*a%MOD;
	return ret;
}
ll P(ll a,ll b)
{return fac[a]*inv[a-b]%MOD;}

int main()
{
	fac[0]=1;
	for(int i=1;i<=MAXN;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[MAXN]=quickpow(fac[MAXN],MOD-2);
	for(int i=MAXN-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%MOD;
	
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	dp[A-1][0]=1;
	for(int i=A;i<=B;i++)
	{
		for(int j=0;j<=n;j++)
			dp[i][j]=dp[i-1][j];
		for(int j=0;j<=n;j++)
			for(int k=C,cur=quickpow(inv[i],C);j+k*i<=n&&k<=D;k++,cur=cur*inv[i]%MOD)
				if(dp[i-1][j]) (dp[i][j+k*i]+=dp[i-1][j]*P(n-j,k*i)%MOD*cur%MOD*inv[k]%MOD)%=MOD;
	}
	printf("%lld",dp[B][n]);
	return 0;
}