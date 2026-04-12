#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int dp[110][2][5];

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();
    dp[0][0][0] = 1;
    rep(i, N) rep(less, 2) rep(k, 4) {
        int x = less ? 9 : S[i] - '0';
        rep(d, x + 1) {
            dp[i + 1][less || d < x][k + (d > 0)] += dp[i][less][k];
        }
    }
    cout << dp[N][0][K] + dp[N][1][K] << '\n';
    return 0;
}
