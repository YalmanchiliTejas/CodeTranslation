#include "bits/stdc++.h"

using namespace std;
using ll = long long;
ll a[200005];
const ll mod = 1e9 + 7;
ll qpow(ll x,ll n,ll mod)
{
    ll res =1;
    while(n>0)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll tmp = sum - a[i];
        tmp += mod;
        tmp %= mod;
        ans += a[i] * tmp;
        ans %= mod;
    }
    ans *= qpow(2, mod - 2, mod);
    ans %= mod;
    cout << ans << endl;

    return 0;
}