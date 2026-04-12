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

    ll dp[N + 1][S + 1] = {};
    REP(i, 0, N) {
        dp[i][0] = (dp[i][0] + 1) % MOD;
        REP(j, 0, S + 1) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j + A[i] < S + 1) dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % MOD;
        }
    }

    ll ans = 0;
    REP(i, 1, N + 1) ans = (ans + dp[i][S]) % MOD;
    cout << ans << endl; 
    return 0;
}