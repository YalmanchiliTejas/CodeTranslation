#include <bits/stdc++.h>
using namespace std;

int to_int(char s) {
    return s - '0';
}

int main() {
    string S;  cin >> S;
    int N = S.size();
    int K;  cin >> K;

    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(K + 1, vector<long long>(2)));
    dp[0][K][1] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int f = 0; f < 2; ++f) {
                for (int nd = 0; nd < 10; ++nd) {
                    int nj = j, nf = f;
                    if (nd != 0) --nj;
                    if (nj < 0) continue;
                    if (f) {
                        if (nd > to_int(S[i])) continue;
                        if (nd < to_int(S[i])) nf = 0;
                    }
                    dp[i + 1][nj][nf] += dp[i][j][f];
                }
            }
        }
    }

    cout << dp[N][0][0] + dp[N][0][1] << endl;
}
