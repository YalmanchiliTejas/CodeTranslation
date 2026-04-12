#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n) sum += a[i];

    ll ans = 0;
    rep(i, n) {
        sum -= a[i];
        ans += sum % MOD * a[i] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}