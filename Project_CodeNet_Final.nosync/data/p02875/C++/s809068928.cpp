#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5,mod=998244353;
typedef long long ll;
ll f[N],invf[N],p[N];
int n;
ll C(ll n,ll m)
{
    return f[n]*invf[n-m]%mod*invf[m]%mod;
}
ll qpow(ll a,ll n)
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
int main()
{
    f[0]=p[0]=f[1]=invf[0]=invf[1]=1;
    for(int i=2;i<N;i++)
    {
        f[i]=f[i-1]*i%mod;
        invf[i]=(mod-mod/i)*invf[mod%i]%mod;
    }
    for(int i=2;i<N;i++) invf[i]=invf[i]*invf[i-1]%mod;
    for(int i=1;i<N;i++) p[i]=p[i-1]*2%mod;
    int n;scanf("%d",&n);
    ll ans=qpow(3,n),res=0;
    for(int i=n/2+1;i<=n;i++)
        res=(res+C(n,i)*p[n-i])%mod;
    ans=(ans-res*2)%mod;
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
}
