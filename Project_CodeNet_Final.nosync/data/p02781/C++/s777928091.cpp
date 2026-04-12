#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    string N; int K; cin >> N >> K;

    ll dp[N.size() + 1][K + 2][2] = {};
    dp[0][0][0] = 1;

    // keta dp
    REP(i, 0, N.size()) {
        int n = N[i] - '0';
        REP(j, 0, K + 1) {
            REP(k, 0, 2) {
                if (k == 0) {
                    REP(l, 0, n + 1) {
                        dp[i + 1][j + (l != 0)][l < n] += dp[i][j][k];
                    }
                } else {
                    REP(l, 0, 10) {
                        dp[i + 1][j + (l != 0)][k] += dp[i][j][k];
                    }
                }
            }
        }
    }
    cout << dp[N.size()][K][0] + dp[N.size()][K][1] << endl;
    return 0;
}