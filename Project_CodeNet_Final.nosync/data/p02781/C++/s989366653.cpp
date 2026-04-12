#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

ll dp[105][105][2][2]; // dp[i][j][k][r]...i:桁数, j:0でない桁の数, k:0以外の値を使ったか, r:未満フラグ

int main() {
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        int t = s[i] - '0';
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                for (int r = 0; r < 2; r++) {
                    for (int v = 0; v <= (r ? 9 : t); v++) {
                        dp[i + 1][j + (v ? 1 : 0)][k || v][r || (v < t)] += dp[i][j][k][r];
                    }
                }
            }
        }
    }
    ll ans = dp[n][K][1][0] + dp[n][K][1][1];
    cout << ans << endl;
}