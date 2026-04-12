#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int data[n + 1];
    for (int i = 1; i <= n; ++i) cin >> data[i];
    int dp[n + 1], pref[n + 1];
    for (int i = 0; i <= n; ++i) {
        pref[i] = 0;
        dp[i] = 0;
    }
    dp[1] = 0;
    pref[1] = data[1];
    for (int i = 3; i <= n; i += 2) pref[i] = pref[i - 2] + data[i];
    for (int i = 2; i <= n; ++i) {
        if (i & 1) dp[i] = max(dp[i - 1], dp[i - 2] + data[i]);
        else dp[i] = max(data[i] + dp[i - 2], pref[i - 1]);
    }
    cout << dp[n];
    return 0;
}
