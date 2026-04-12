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
#define USE_STRICT_INT
using i64 = int64_t;
#ifndef USE_STRICT_INT
#define int i64
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF = (1 << 30);
constexpr i64 INFL = (1LL << 62);
constexpr i64 MOD = 1000000007;

vector<vector<vector<int>>> dp(110, vector<vector<int>>(4, vector<int>(2, 0)));

void main_sub(void) {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i, n) rep(j, 4) rep(k, 2) {
        int x = s[i] - '0';
        rep(d, 10) {
            int ni = i + 1, nj = j, nk = k;
            if (d != 0) nj++;
            if (nj > m) continue;
            if (k == 0) {
                if (d > x) continue;
                if (d < x) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }
    cout << dp[n][m][0] + dp[n][m][1] << endl;
    return;
}