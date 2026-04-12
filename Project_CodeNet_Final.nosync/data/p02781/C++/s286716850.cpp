#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

string S;
int K;
int dp[110][2][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> K;
    dp[0][0][0] = 1;
    REP (i, S.size()) REP (k, K + 1) {
        if (S[i] == '0') {
            dp[i + 1][0][k] += dp[i][0][k];
        } else {
            REP (d, S[i] - '0' + 1) {
                if (d == 0) dp[i + 1][1][k] += dp[i][0][k];
                else if (d < S[i] - '0' && k + 1 <= K) dp[i + 1][1][k + 1] += dp[i][0][k];
                else if (k + 1 <= K) dp[i + 1][0][k + 1] += dp[i][0][k];
            }
        }
        dp[i + 1][1][k] += dp[i][1][k];
        if (k + 1 <= K) FOR (d, 1, 10) dp[i + 1][1][k + 1] += dp[i][1][k];
    }
    cout << dp[S.size()][0][K]  + dp[S.size()][1][K] << endl;
}