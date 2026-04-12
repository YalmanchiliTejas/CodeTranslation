#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<ll> a(n);
    for (ll &i : a) cin >> i;

    ll cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + cur * a[i]) % mod;
        cur = (cur + a[i]) % mod;
    }

    cout << ans;
}
