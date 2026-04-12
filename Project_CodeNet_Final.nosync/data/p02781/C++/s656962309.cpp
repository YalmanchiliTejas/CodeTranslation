#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int dp[105][2][4];

int main() {
    string S;
    int K;
    cin >> S >> K;
    int L = S.size();

    dp[0][0][0] = 1;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= K; k++) {
                int D = S[i] - '0';
                for (int d = 0; d <= 9; d++) {
                    int ni = i + 1, nj = j, nk = k;

                    // jを決定
                    if (j == 0) {
                        if (d < D) nj = 1;
                        if (d > D) break;
                    } else {
                        nj = 1;
                    }

                    if (d != 0) nk++;
                    if (nk > K) continue;
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[L][0][K] + dp[L][1][K] << endl;
    return 0;
}