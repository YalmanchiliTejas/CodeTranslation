#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> s(n), t(n);
    for (int i = 0; i < n; i++) {
        s[i] = a[i];
        if (i - 2 >= 0) {
            s[i] += s[i - 2];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        t[i] = a[i];
        if (i + 2 < n) {
            t[i] += t[i + 2];
        }
    }
    if (n % 2 == 0) {
        ll ans = max(s[n - 1], s[n - 2]);
        for (int i = 1; i < n - 2; i += 2) {
            ans = max(ans, s[i - 1] + t[i + 2]);
        }
        cout << ans << '\n';
        return 0;
    }
    ll ans = max({s[n - 3], s[n - 2], t[2]});
    for (int i = 1; i + 3 < n; i += 2) {
        ans = max(ans, s[i - 1] + t[i + 3]);
    }
    for (int i = 0; i + 3 < n; i++) {
        ans = max(ans, s[i] + t[i + 3]);
    }
    vector<vector<ll>> dp(3, vector<ll>(n, -1e16));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            dp[0][i] = a[i] + (i ? dp[0][i - 2] : 0);
            if (i) {
                dp[2][i] = a[i] + dp[2][i - 2];
                if (i >= 3) dp[2][i] = max(dp[2][i], dp[1][i - 3] + a[i]);
            }
        } else if (i >= 3) {
            dp[1][i] = dp[1][i - 2] + a[i];
            dp[1][i] = max(dp[1][i], dp[0][i - 3] + a[i]);
        }
    }
    debug(dp[2][n - 1]);
    ans = max(ans, dp[2][n - 1]);
    cout << ans << '\n';
    return 0;
}
