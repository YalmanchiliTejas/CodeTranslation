#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=2e5+5;
int n,m,k;
ll f[N],invf[N];
vector<int>v;
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
void init()
{
    f[0]=invf[0]=1;
    for(int i=1;i<=200000;i++)
        f[i]=f[i-1]*i%mod,invf[i]=qpow(f[i],mod-2);
}
ll c(int n,int m)
{
    return f[n]*invf[n-m]%mod*invf[m]%mod;
}
ll solve(ll n,ll m,ll k)
{
    ll ans=0;
    for(int i=1;i<n;i++)
        ans=(ans+c(n*m-2,k-2)*(n-i)%mod*m%mod*m%mod*i%mod)%mod;
    return ans;
}
int main()
{
    init();
    scanf("%d%d%d",&n,&m,&k);
    printf("%lld\n",(solve(n,m,k)+solve(m,n,k))%mod);
}
