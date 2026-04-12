#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define ll long long
const ll mod=1e9+7;
ll fac[N];

void init()
{
    fac[0]=1;
    for(int i=1;i<=N;i++)
        fac[i]=fac[i-1]*i%mod;
}
ll qpow(ll x,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)
            res=res*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return res;
}
ll C(ll n,ll k)
{
    ll res=fac[n]*qpow(fac[n-k]+mod,mod-2)%mod;
    res=res*qpow(fac[k],mod-2)%mod;
    return res;
}
int main()
{
    init();
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    ll ans=C(n*m,k)*C(k,2)%mod;
    ans=ans*(n+m)%mod;
    ans=ans*qpow(3,mod-2)%mod;
    cout<<ans%mod;
    return 0;
}
