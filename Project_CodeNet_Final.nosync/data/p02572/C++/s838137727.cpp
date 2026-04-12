#include "bits/stdc++.h"

using namespace std;
using ll = long long;
#define endl '\n'
#define all(v) v.begin(), v.end()

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll ans = 0;
    ll mod = 1e9+7;
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    for (int i = 0; i < n; i++) {
        sum -= a[i];
        ans += ((a[i] % mod) * (sum%mod)) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
