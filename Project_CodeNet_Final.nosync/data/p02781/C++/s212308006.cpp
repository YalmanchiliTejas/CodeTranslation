#include <bits/stdc++.h>
using namespace std;

int dp[101][4][2];

int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;

    int n = (int)S.size();

    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                int digit = S[i] - '0';
                for (int d = 0; d <= 9; d++) {
                    int ni = i + 1, nj = j, nk = k;
                    if (d != 0) nj++;
                    if (nj > K) continue;
                    if (k == 0) {
                        if (d > digit) continue;
                        if (d < digit) nk = 1;
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