#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 998244353;

ll powmod(ll a, ll b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = int(res * 1ll * a % mod), --b;
        } else {
            a = int(a * 1ll * a % mod), b >>= 1;
        }
    }
    return res;
}

ll reverse(ll a) {
    return powmod(a, mod - 2);
}

int main() {
    int n;
    cin >> n;
    vector<ll> two(n + 1);
    vector<ll> three(n + 1);
    vector<ll> fact(n + 1);
    vector<ll> finv(n + 1);
    two[0] = three[0] = fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        three[i] = (3ll * three[i - 1]) % mod;
        two[i] = (2ll * two[i - 1]) % mod;
        fact[i] = (1ll * i * fact[i - 1]) % mod;
    }
    finv[n] = reverse(fact[n]);
    for (int i = n - 1; i >= 0; --i) {
        finv[i] = ((i + 1) * finv[i + 1]) % mod;
    }
    auto C = [fact, finv](int n, int k) {
      return (((fact[n] * finv[k]) % mod) * finv[n - k]) % mod;
    };
    ll ans = three[n];
    for (int i = n / 2 + 1; i <= n; ++i) {
        ans = (mod + ans - 2 * C(n, i) * two[n - i]) % mod;
    }
    cout << ans;
    return 0;
}