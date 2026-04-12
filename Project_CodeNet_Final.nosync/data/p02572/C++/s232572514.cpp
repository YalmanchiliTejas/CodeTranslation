// time-limit: 2000
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, mxN = 2e5;

void solve() {
    long long s = 0, ans = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        s -= a[i];
        (ans += (a[i] * (s%MOD)) %MOD) %= MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
