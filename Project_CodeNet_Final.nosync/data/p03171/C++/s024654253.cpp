#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long dp[n][n], a[n], pfx[n + 1];
    pfx[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pfx[i + 1] = pfx[i] + a[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int r = i + len - 1;
            if (len == 1) {
                dp[i][r] = a[i];
                continue;
            }
            dp[i][r] = pfx[r + 1] - pfx[i] - min(dp[i + 1][r], dp[i][r - 1]);
        }
    }
    if (n == 1) cout << dp[0][n - 1];
    else cout << dp[0][n - 1] - min(dp[1][n - 1], dp[0][n - 2]);
    return 0;
}
