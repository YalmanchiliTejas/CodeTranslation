#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    vvi dp(n, vi(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = as[i];
                continue;
            }
            dp[i][j] = max(as[i] - dp[i + 1][j], as[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
}