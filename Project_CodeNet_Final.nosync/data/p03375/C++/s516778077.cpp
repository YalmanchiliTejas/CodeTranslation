#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
int n,mod,c[N][N];
ll g[N][N],f[N];
ll qpow(ll a,ll n,ll mod)
{
    ll ans=1;
    while(n)
    {
       if(n&1) ans=ans*a%mod;
       a=a*a%mod;
       n>>=1;
    }
    return ans;
}
ll C(int n,int m)
{
    if(m==0||n==m) return 1;
    if(m==1) return n;
    if(c[n][m]) return c[n][m];
    return c[n][m]=(C(n-1,m-1)+C(n-1,m))%mod;
}
int main()
{
    scanf("%d%d",&n,&mod);
    g[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
    {
        g[i][j]=g[i-1][j]*(j+1)%mod;
        if(j-1>=0)
            (g[i][j]+=g[i-1][j-1])%=mod;
    }
    for(int i=0;i<=n;i++)
    {
        ll s=qpow(2,n-i,mod-1);
        s=qpow(2,s,mod);
        ll t=qpow(2,n-i,mod),x=1;
        for(int j=0;j<=i;j++)
        {
            g[i][j]=g[i][j]*s%mod*x%mod;
            (f[i]+=g[i][j])%=mod;
            x=x*t%mod;
        }
    }
    ll ans=0;
    for(int i=0,t=1;i<=n;i++,t*=-1)
        ans=(ans+t*f[i]*C(n,i))%mod;
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
}
