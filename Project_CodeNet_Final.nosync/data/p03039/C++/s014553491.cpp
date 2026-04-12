#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll kai[(1<<18)];

ll mp(ll a, ll b) {
    if (b == 0) return 1LL;
    if (b == 1) return a;
    ll ans = mp(a, b/2);
    ans *= ans;
    ans %= mod;
    if (b&1) ans *= a;
    return ans % mod;
}

ll inv(ll k) {
    return mp(k, mod - 2);
}

ll c(ll n, ll k) {
    if (k == 0 || n == k) return 1LL;
    return kai[n] * inv(kai[k]) % mod * inv(kai[n - k]) % mod;
}

ll f(ll n, ll m, ll k) {
    ll ans = 0;
    for (ll i = 1LL; i <= n; i++) {
        ans += i * (n - i) % mod * m % mod * m % mod * c(n * m - 2, k - 2) % mod;
        ans %= mod;
    }
    return ans;
}

void init() {
    kai[1] = 1;
    for (ll i = 2; i < (1 << 18); i++) {
        kai[i] = kai[i-1] * i;
        kai[i] %= mod;
    }
}

int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    init();
    cout << (f(n,m,k) + f(m,n,k)) % mod << endl;
    return 0;
}
