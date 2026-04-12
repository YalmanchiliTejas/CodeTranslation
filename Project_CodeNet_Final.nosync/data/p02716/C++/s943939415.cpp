#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<ll> dp(n), dpeven(n);
    dp[0] = 0;
    dp[1] = max(a[0], a[1]);
    dpeven[0] = a[0];
    dpeven[1] = max(a[0], a[1]);
    for (int i = 2; i < n; ++i) {
        if (i % 2 == 0) {
            dpeven[i] = a[i] + dpeven[i - 2];
            dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
        } else {
            dpeven[i] = max(a[i] + dpeven[i - 2], a[i - 1] + dpeven[i - 3]);
            dp[i] = max(a[i] + dp[i - 2], a[i - 1] + dpeven[i - 3]);
        }
    }
    cout << dp[n - 1];
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);

    solve();
}
