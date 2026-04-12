#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
template <class T> void chmax(T &x, T y) { if (x < y) x = y; }
const Int INF = 1e18;
Int dp[200020][2][3];
int main() {
    int N; cin >> N;
    vector<int> A(N); for (auto &a : A) cin >> a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    if (N % 2 == 0) {
        dp[0][1][1] = A[0];
        dp[0][0][0] = 0;
    } else {
        dp[0][1][2] = A[0];
        dp[0][0][1] = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == 1 || i + 1 >= N - k) {
                    chmax(dp[i + 1][0][k], dp[i][j][k]);
                } else {
                    if (k != 0) {
                        chmax(dp[i + 1][0][k - 1], dp[i][j][k]);
                    }
                    chmax(dp[i + 1][1][k], dp[i][j][k] + A[i + 1]);
                }
            }
        }
    }
    Int ans = -INF;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 3; k++) {
            chmax(ans, dp[N - 1][j][k]);
        }
    }
    cout << ans << '\n';
    return 0;
}
