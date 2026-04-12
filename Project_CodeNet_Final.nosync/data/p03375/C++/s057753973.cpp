#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int mod=998244353;
int dp[maxn][maxn];
int C[maxn][maxn];
int n;
int Pow(int a,long long k,int M=mod)
{
    int ret=1;
    while(k)
    {
        if(k&1)ret=ret*1LL*a%M;
        a=a*1LL*a%M;
        k>>=1;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&mod);
    C[0][0]=1,dp[0][0]=1;
    for(int i=1;i<=n+1;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod,dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*1LL*j)%mod;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    {
         int tmp=(i&1?mod-1:1)*1LL*C[n][i]%mod*Pow(2,Pow(2,n-i,mod-1))%mod;
         int sum=0,p2=Pow(2,n-i);
         for(int j=0,t=1;j<=i;j++,t=t*1LL*p2%mod)sum=(sum+dp[i+1][j+1]*1LL*t)%mod;
         ans=(ans+sum*1LL*tmp)%mod;
    }
    printf("%d\n",ans);
}