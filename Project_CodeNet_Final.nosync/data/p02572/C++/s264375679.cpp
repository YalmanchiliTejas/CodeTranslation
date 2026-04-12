#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

ll modexp(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

ll modinv(ll x) {
    return modexp(x, mod - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 = (sum1 + a[i]) % mod;
        sum2 = (sum2 + a[i] * (ll)a[i] % mod) % mod;
    }

    sum1 = sum1 * sum1 % mod;
    ll ans = (sum1 - sum2 + mod) % mod;
    cout << ans * modinv(2) % mod << "\n";
    return 0;
}