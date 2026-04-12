#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;

    int n = (int)s.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(K + 1, vector<int>(2)));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 2; k++) {
                int nd = s[i] - '0';
                for (int d = 0; d <= 9; d++) {
                    int ni = i + 1, nj = j, nk = k;
                    if (d != 0) nj++;
                    if (nj > K) continue;
                    if (k == 0) {
                        if (d > nd) continue;
                        if (d < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    int res = dp[n][K][0] + dp[n][K][1];
    cout << res << endl;
    return 0;
}