#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &&x : a) cin >> x;

    ll dp[2][n + 1][n + 1];
    for (int size = 1; size <= n; ++size) {
        for (int l = 0; l + size <= n; ++l) {
            if (size == 1) {
                dp[0][l][l] = a[l];
                dp[1][l][l] = -a[l];
            }
            else {
                int r = l + size - 1;
                // 太郎君 maximize
                dp[0][l][r] = max(dp[1][l + 1][r] + a[l],
                                  dp[1][l][r - 1] + a[r]);
                // 次郎君 minimize
                dp[1][l][r] = min(dp[0][l + 1][r] - a[l],
                                  dp[0][l][r - 1] - a[r]);

            }
        }
    }

    cout << dp[0][0][n - 1] << endl;

    return 0;
}
