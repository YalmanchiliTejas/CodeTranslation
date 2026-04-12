#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[101][2][101];

void solve() {
    string N;
    cin >> N;
    int K;
    cin >> K;
    int L = N.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < L; ++i) {
        const int D = N[i] - '0';
        for (int smaller = 0; smaller < 2; ++smaller) {
            for (int k = 0; k <= K; ++k) {
                for (int d = 0; d <= (smaller ? 9 : D); ++d) {
                    if (d != 0) {
                        dp[i+1][smaller || (d < D)][k+1] += dp[i][smaller][k];
                    } else {
                        dp[i+1][smaller || (d < D)][k] += dp[i][smaller][k];
                    }
                }
            }
        }
    }
    cout << dp[L][0][K] + dp[L][1][K] << endl;
}

int main() {
    solve();
    return 0;
}
