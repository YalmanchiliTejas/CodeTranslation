#include "bits/stdc++.h"
#define int long long

using namespace std;

int dp[3010][3010];

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i + 1] = a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;
            dp[l][r] = max(
                            sum[r] - sum[l] - dp[l + 1][r],
                            sum[r] - sum[l] - dp[l][r - 1]
                           );
        }
    }
    cout << dp[0][n] - (sum[n] - dp[0][n]) << endl;
}
