#include <bits/stdc++.h>
using namespace std;
void main_sub(void);
int main(int argc, char* argv[]) {
    main_sub();
    return 0;
}
// int を int64_t にする
// g++ に -DUSE_STRICT_INT をつけるか、
// 下のコメントアウトを外すと無効化
// #define USE_STRICT_INT
using i64 = int64_t;
#ifndef USE_STRICT_INT
#define int i64
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF = (1 << 30);
constexpr i64 INFL = (1LL << 62);
constexpr i64 MOD = 1000000007;

int dp[105][4][2];

void main_sub(void) {
    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;
    dp[0][0][0] = 1;  // 空集合が1つって意味？
    rep(i, n) {
        rep(j, 4) {
            rep(k, 2) {
                int nd = s[i] - '0';
                rep(d, 10) {
                    int ni = i + 1;
                    int nj = j;
                    int nk = k;
                    if (d != 0) nj++;
                    if (nj > K) continue;
                    if (k == 0) {
                        if (d > nd) continue;
                        if (d < nd) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[n][K][0] + dp[n][K][1] << endl;
    return;
}