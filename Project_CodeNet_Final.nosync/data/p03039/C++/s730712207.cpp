#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define pii pair<int,int>
typedef long long ll;
const ll mod=1e9+7;
#define MAXNUM 222222
ll fact[MAXNUM],ifact[MAXNUM];

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res;
}
void sub(ll &a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
}
ll getC(int a,int b)
{
    return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
}
int main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    fact[0]=ifact[0]=1;
    rep(i,1,n*m+1)fact[i]=fact[i-1]*i%mod,ifact[i]=qpow(fact[i],mod-2);
    ll x=getC(n*m-2,k-2),res=0;
    rep(i,1,n+1)
        (res+=x*i%mod*m%mod*(m*(i-1)))%=mod,sub(res,x*i%mod*m%mod*(n*m-m*i)%mod);
    rep(i,1,m+1)
        (res+=x*i%mod*n%mod*(n*(i-1)))%=mod,sub(res,x*i%mod*n%mod*(n*m-n*i)%mod);
    printf("%lld\n",res);
}