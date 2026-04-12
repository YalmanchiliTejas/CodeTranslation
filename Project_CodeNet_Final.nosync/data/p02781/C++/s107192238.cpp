#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

ull solve(string N, ull K) {
    vector<vector<vector<ull>>> dp(N.length() + 1, vector<vector<ull>>(2, vector<ull>(K + 2, 0)));

    dp[0][0][0] = 1;

    int D;
    for (int i = 0; i < N.length(); i++) {
        D = N[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= K; k++) {
                for (int d = 0; d <= (j ? 9 : D); d++) {
                    dp[i + 1][j || (d < D)][k + (d == 0 ? 0 : 1)] += dp[i][j][k];
                }
            }
        }
    }

    ull ans = dp[N.length()][0][K] + dp[N.length()][1][K];
    return ans;
}


int main() {
    string N;
    ull K;
    cin >> N >> K;
    cout << solve(N, K) << endl;
}
