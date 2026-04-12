#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define P 1000000007
#define rep(i,n) for(i=0;i<n;++i)
#define re(i,a,n) for(i=a;i<=n;++i)
#define repr(i,a,n) for(i=a;i>=n;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second


ll binpow(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
   while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return binpow(n, p-2, p);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n,i,f=0,j,ans=0,k,x,r,l,t;
    cin >> n ;
    vector<ll> a(n);
    ll sum=0;
    rep(i,n) 
    {
          cin >> a[i];
          sum+=a[i];
          sum%=P;
    }
    
    ll t1;
    rep(i,n)
    {
         sum=(sum-a[i]+P)%P;
         t1=(a[i]*sum)%P;
         ans=(ans+t1)%P;
    }
    cout << ans << endl ;
    return 0;
}