#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define int long long

using ll = long long;
using ld = double;
using pii = pair <int, int>;

const int oo = 1e9 + 4;
const int SZ = 2e5 + 4;
const ll M = 998244353;

int n, s;
vector <int> a;
ll k[3010];

void read() {
    cin >> n >> s;
    a.resize(n);
    for (auto &t : a) cin >> t;
}

void solve() {
    k[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s - a[i] >= 0) ans += 1ll * k[s - a[i]] * (n - i) % M;
        ans %= M;
        for (int j = s; j >= a[i]; j--)
            k[j] = (k[j] + k[j - a[i]]) % M;
        k[0]++;
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
}
