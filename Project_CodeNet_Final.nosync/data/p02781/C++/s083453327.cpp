#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

string S;
int K;
int dp[110][2][5];

void _main() {
    cin >> S >> K;
    dp[0][0][0] = 1;
    REP (i, S.size()) REP (j, 2) REP (k, K + 1) {
        int lim = (j == 0 ? S[i] - '0' : 9);
        for (int d = 0; d < lim + 1; ++d) {
            dp[i + 1][j | (d < lim)][k + (d > 0)] += dp[i][j][k];
        }
    }
    cout << (dp[S.size()][0][K] + dp[S.size()][1][K]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    _main();
    return 0;
}