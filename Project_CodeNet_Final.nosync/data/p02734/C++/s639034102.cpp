#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
const int MOD = 998244353;
Int dp[3010][3010];
int main() {
    int N, S; cin >> N >> S;
    vector<int> A(N); for (auto &a : A) cin >> a;
    for (int i = 0; i < N; i++) dp[i][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 3000; j++) {
            (dp[i + 1][j] += dp[i][j]) %= MOD;
        }
        for (int j = 0; j + A[i] <= 3000; j++) {
            (dp[i + 1][j + A[i]] += dp[i][j]) %= MOD;
        }
    }
    Int ans = 0;
    for (int i = 1; i <= N; i++) ans += dp[i][S];
    cout << ans % MOD << endl;
    return 0;
}
