#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define len(a) (int)a.size()
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    vector<ll> s = a;
    rep(i, n-1) {
        s[i+1] += s[i];
        s[i+1] %= MOD;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i] * s[i-1] % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
