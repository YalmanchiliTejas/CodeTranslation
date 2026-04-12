#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[2][4][105];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string n;
    int K;
    cin >> n >> K;
    int m = n.size();

    dp[false][0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= K; ++j) {
            // less?: true
            // next: 0
            dp[true][j][i + 1] += dp[true][j][i];
            for (int k = 1; k < 10; ++k) {
                if (j == K) break;
                dp[true][j + 1][i + 1] += dp[true][j][i]; 
            }

            // less?: false
            // next: 0
            dp[n[i] != '0'][j][i + 1] += dp[false][j][i];
            for (int k = 1; k <= n[i] - '0'; ++k) {
                if (j == K) break;
                dp[n[i] - '0' != k][j + 1][i + 1] += dp[false][j][i]; 
            }
        }
    }
    cout << dp[false][K][m] + dp[true][K][m] << "\n";
    return 0;
}