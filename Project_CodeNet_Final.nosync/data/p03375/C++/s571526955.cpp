#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;
typedef long long ll;
ll mod,f[maxn+5],s[maxn+5][maxn+5],c[maxn+5][maxn+5],pw[maxn+5],pw1[maxn+5];
int n;
ll Pow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{

    scanf("%d%lld",&n,&mod);
    c[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    for(int i=0;i<=n;++i) s[i][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j) s[i][j]=(s[i-1][j-1]+(j+1)*s[i-1][j]%mod)%mod;
   pw[0]=1;
   pw1[0]=1;
   for(int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
   for(int i=1;i<=n;++i) pw1[i]=pw1[i-1]*2%(mod-1);
    for(int i=0;i<=n;++i)
        for(int j=0;j<=i;++j)
            f[i]=(f[i]+s[i][j]*Pow(pw[n-i],j,mod)%mod*Pow(2LL,pw1[n-i],mod)%mod)%mod;

    //for(int i=0;i<=n;++i) printf("%d : %lld\n",i,f[i]);
    ll ans=0;
    for(int i=0;i<=n;++i)
    {
        ll cnt=c[n][i]*f[i]%mod;
        if(i&1) cnt=-cnt;
        ans=(ans+cnt)%mod;
    }
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
