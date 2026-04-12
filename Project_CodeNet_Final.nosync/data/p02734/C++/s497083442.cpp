#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 998244353
using namespace std;
using ll = long long;

int main() {
    int N, S; cin >> N >> S;
    vector<int> A(N);
    REP(i, 0, N) cin >> A[i];

    ll dp[N + 1][S + 1][3] = {};
    dp[0][0][0] = 1;
    REP(i, 0, N) {
        REP(j, 0, S + 1) {
            REP(k, 0, 3) {
                REP(l, k, 3) {
                    dp[i + 1][j][l] = (dp[i + 1][j][l] + dp[i][j][k]) % MOD;
                    if (j + A[i] < S + 1 && k != 2 && l != 0) dp[i + 1][j + A[i]][l] = (dp[i + 1][j + A[i]][l] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    cout << dp[N][S][2] << endl;
    return 0;
}