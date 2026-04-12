#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

//dp[桁][0でない数字をいくつ使ったか][n未満か]
int dp[105][4][2] = {};

int main() {

    string s; cin >> s;
    int n = s.length();
    int K; cin >> K;

    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 2; ++k) {
                int nd = s[i] - '0'; //次に見る桁の数字

                for (int d = 0; d < 10; ++d) {
                    int ni = i + 1;
                    int nj = j;
                    int nk = k;

                    if (d != 0) nj++; //次の数字が0以外ならnjをインクリメント
                    if (nj > K) continue; //0以外を使った回数が求めるものより大きい場合は不要
                    if (k == 0) {
                        if (d > nd) continue; //次に設定しようとする桁の数字が、ndより大きい場合は条件を満たさない
                        if (d < nd) nk = 1; //次に設定しようとする桁の数字が、ndより小さい場合はn未満かが1になる
                    }

                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    int ans = dp[n][K][0] + dp[n][K][1];

    cout << ans << endl;
}