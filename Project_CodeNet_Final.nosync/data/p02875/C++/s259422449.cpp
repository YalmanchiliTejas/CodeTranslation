#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e7;
const ll MOD = 998244353;

int N;
ll ans=1, fact[MAXN+10], invfact[MAXN+10], twopow[MAXN+10], A;

ll mypow(ll x, ll y)
{
    if(y==0) return 1;
    if(y%2) return mypow(x, y-1)*x%MOD;
    ll t=mypow(x, y/2);
    return t*t%MOD;
}

ll inv(ll x) { return mypow(x, MOD-2); }

ll comb(ll n, ll r) { return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD; }

int main()
{
    int i, j;

    scanf("%lld", &N);
    for(i=1; i<=N; i++) ans=ans*3%MOD;

    twopow[0]=1;
    for(i=1; i<=N; i++) twopow[i]=twopow[i-1]*2%MOD;

    fact[0]=1;
    for(i=1; i<=N; i++) fact[i]=fact[i-1]*i%MOD;
    invfact[N]=inv(fact[N]);
    for(i=N; i>=1; i--) invfact[i-1]=invfact[i]*i%MOD;

    for(i=N/2+1; i<=N; i++) A=(A+comb(N, i)*twopow[N-i]%MOD)%MOD;
    ans-=2*A;
    ans=(ans%MOD+MOD)%MOD;
    printf("%lld", ans);
}
