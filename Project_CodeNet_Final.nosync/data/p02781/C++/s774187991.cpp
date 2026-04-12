#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<vector<lint>>> dp(n.size() + 1, vector<vector<lint>>(4, vector<lint>(2, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= (int)n.size(); ++i) {
        // 0
        if (n[i - 1] == '0') {
            for (int j = 0; j <= 3; ++j) {
                dp[i][j][0] += dp[i - 1][j][0];
                dp[i][j][1] += dp[i - 1][j][1];
            }
        } else {
            for (int j = 0; j <= 3; ++j) {
                dp[i][j][1] += dp[i - 1][j][0];
                dp[i][j][1] += dp[i - 1][j][1];
            }
        }
        // 1-9
        for (int j = 1; j <= 3; ++j) {
            dp[i][j][1] += 9 * dp[i - 1][j - 1][1];
            dp[i][j][1] += max(0, n[i - 1] - '1') * dp[i - 1][j - 1][0];
        }
        if (n[i - 1] != '0') {
            for (int j = 1; j <= 3; ++j) {
                dp[i][j][0] += dp[i - 1][j - 1][0];
            }
        }
    }
    cout << dp[n.size()][k][1] + dp[n.size()][k][0] << "\n";
    return 0;
}