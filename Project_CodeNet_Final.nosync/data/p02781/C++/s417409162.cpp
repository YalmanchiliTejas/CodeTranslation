#include <bits/stdc++.h>

using namespace std;

int dp[110][4][2];

int main() {
    string S;
    int K;
    cin >> S >> K;

    int n = S.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {// 上からi桁をみる
        for (int j = 0; j < 4; ++j) {// ０でない数はj個
            for (int k = 0; k < 2; ++k) {// 上からi桁がSと等しければk=0。小さければk=1
                int nd = S[i] - '0';// いま見ている桁の数字
                for (int d = 0; d < 10; ++d) {
                    // 上からi+1桁目に0をおくことは常に可能
                    int nj = j;
                    int nk = k;
                    // 上からi+1桁目に0以外をおくとき
                    if (d != 0) nj++;// 0以外の数字は増える
                    if (nj > K) continue; // 増え過ぎたらだめ
                    if (k == 0) { // Sとの大小の確定/未確定が変わる場合
                        if (d > nd) continue;
                        if (d < nd) nk = 1;
                    }
                    dp[i + 1][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    int ans = dp[n][K][0] + dp[n][K][1];
    cout << ans << endl;
    return 0;
}