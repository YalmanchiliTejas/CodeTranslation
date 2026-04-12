#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#define int long long
using namespace std;
int n,mod;
const int maxn=3086;
int C[maxn][maxn];
int dp[maxn][maxn];
int F[maxn];
int qpow(int a,int b,int p)
{
	int res=1,base=a%p;
	while(b) 
	{
		if(b&1) res=res*base%p;
		b>>=1,base=base*base%p;
	}
	return res;
}
signed main()
{
	scanf("%lld%lld",&n,&mod);
	C[0][0]=1;
	for(int i=1;i<maxn;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	dp[0][0]=1;
	for(int i=1;i<maxn;++i)
	{
		dp[i][0]=1;
		for(int j=1;j<=i;++j)
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*(j+1))%mod;
	}
	int ans=0;
    for (int i=0;i<=n;i++)
    {
        int k=C[n][i];
        if (i&1) k=(mod-k)%mod;
        int x=qpow(2,n-i,mod-1);
        x=qpow(2,x,mod);
        int kind=qpow(2,n-i,mod);
        int cnt=0,y=1;
        for (int j=0;j<=i;j++)
        {
            cnt=(cnt+(dp[i][j]*y%mod))%mod;
            y=kind*y%mod;
        } 
        ans=(ans+(k*cnt%mod*x%mod))%mod;
    }
    printf("%lld\n",ans);
    return 0;
}