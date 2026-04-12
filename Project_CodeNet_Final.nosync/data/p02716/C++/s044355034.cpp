#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <vector <int> > dp(n + 1, vector <int> (2 + n % 2, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        //cout << i << endl;
        if (i - 2 < 0) dp[i][0] = max(dp[i][0], a[i - 1]);
        else {
            dp[i][0] = max(dp[i - 2][0] + a[i - 1], dp[i][0]);
            dp[i][1] = max(dp[i - 2][1] + a[i - 1], dp[i][1]);
            if (n % 2) dp[i][2] = max(dp[i - 2][2] + a[i - 1], dp[i][2]);
        }
        if (i - 3 >= 0) {
            dp[i][1] = max(dp[i][1], dp[i - 3][0] + a[i - 1]);
            if (n % 2) dp[i][2] = max(dp[i][2], dp[i - 3][1] + a[i - 1]);
        }
        if (i - 4 > 0 && n % 2) {
            dp[i][2] = max(dp[i][2], dp[i - 4][0] + a[i - 1]);
        }
    }
    //for (int i = 0; i <= n; ++i) for (int j = 0; j < 2 + n % 2; ++j) cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    int ans = dp[n][1];
    if (n % 2 == 0) ans = max(ans, dp[n][0]);
    if (n % 2) ans = max(ans, dp[n][2]);
    ans = max(ans, dp[n - 1][0]);
    if (n % 2) ans = max(ans, dp[n - 1][1]);
    if (n % 2) {
        ans = max(ans, dp[n - 2][0]);
    }
    cout << ans;
    /*if (n % 2 == 0) {
        int od = 0, ev = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2) od += a[i];
            else ev += a[i];
        }
        int ans = max(od, ev);
        int odl = 0, odr = 0, evl = 0, evr = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2) odr += a[i];
            else evr += a[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            if (i % 2) {
                odr -= a[i];
                ans = max(ans, evl + odr);
                odl += a[i];
            }
            else {
                evr -= a[i];
                ans = max(ans, odl + evr);
                evl += a[i];
            }
        }
        cout << ans;
        return;
    }
    int odl = 0, odr = 0, evl = 0, evr = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2) odr += a[i];
        else evr += a[i];
    }
    int ans = -1e18;
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2) {
            odr -= a[i];
            ans = max(ans, evl + odr);
            odl += a[i];
        }
        else {
            evr -= a[i];
            ans = max(ans, odl + evr);
            evl += a[i];
        }
    }
    cout << ans;*/
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
