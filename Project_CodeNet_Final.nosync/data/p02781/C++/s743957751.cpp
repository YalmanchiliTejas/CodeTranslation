#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

string S;
int K;

int dp[105][4][2];

int main() {
    cin >> S;
    int N = S.size();
    cin >> K;

    dp[0][0][0] = 1;

    // i 何桁目まで
    // j 非ゼロの数 0 ~ 3
    // k 一致したかどうか 
    // 0: N と一致
    // 1: N 以下が確定
    rep(i, N)rep(j, 4)rep(k, 2) {
        int nd = S[i] - '0';

        // 遷移
        rep(d, 10) {
            int ni = i + 1, nj = j, nk = k;
            if (d != 0) nj++;
            if (nj > K) continue;
            if (k == 0) {
                if (d > nd) continue;
                if (d < nd) nk = 1;
            }
            dp[ni][nj][nk] += dp[i][j][k];
        }
    }

    int ans = dp[N][K][0] + dp[N][K][1];
    cout << ans << endl;
}