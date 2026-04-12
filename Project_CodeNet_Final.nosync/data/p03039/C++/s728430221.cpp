#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll fac[200005];
ll ifac[200005];
int n,m,k;
const ll mod = 1000000007;
ll mexp(ll x, ll y)
{
    if(!y) return 1;
    if(y & 1) return x * mexp(x*x%mod, y>>1) % mod;
    else return mexp(x*x%mod, y>>1);
}
ll binom(ll a, ll b)
{
    if(a < b) return 0;
    ll ret = 1;
    ret = fac[a];
    ret *= ifac[a-b];
    ret %= mod;
    ret *= ifac[b];
    ret %= mod;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >>k;
    fac[0] = 1;
    for(int i=1;i<=n*m;i++)
        fac[i] = i * fac[i-1] % mod;
    ifac[n*m] = mexp(fac[n*m], mod-2);
    for(int i=n*m-1;i>=0;i--)
        ifac[i] = (i+1) * ifac[i+1] % mod;

    ll ans = binom(n*m-2, k-2);
    ll ans2 = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ll tmp = 0;
            tmp = m * (binom(i, 2) + binom(n-i+1, 2));
            tmp += n * (binom(j, 2) + binom(m-j+1, 2));
            ans2 = (ans2 + tmp) % mod;
        }
    }
    ans2 = ans2 * mexp(2, mod-2) % mod;
    cout << ans * ans2 % mod;
}