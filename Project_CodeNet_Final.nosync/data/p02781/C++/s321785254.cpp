#include <bits/stdc++.h>
using namespace std;
using Int = long long;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define LEN(x) ((int)(x).length())
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &value) {
    std::fill((T *)array, (T *)(array + N), value);
}
#define PUTS(x) cout << (x) << endl;
int main() {
    string s;
    int k;
    cin >> s >> k;
    auto len = LEN(s);
    Int dp[150][150][2]; // dp[i][j][k] 首位からi桁目(0-index)まで調べ終えた時点で0以外がj個含まれるものの個数。ただし k=1 はそのうちn以下であることが確定しているものの数，k=0は確定していない（すなわち第i桁までずっとnと一致している）ものの個数。
    Fill(dp, 0); // 初期化
    rep(i, len) {
        auto pivot = s[i] - '0'; // 第i桁
        if (i == 0) { // 首位
            dp[0][0][1] = 1; // 首位が0のものは0以外を0個含み確定
            dp[0][1][1] = pivot - 1; // 首位が 1,2,3,..,pivot-1 のものは0以外を1個含み確定
            dp[0][1][0] = 1; // 首位が pivot のものは0以外を1個含み未確定
        } else {
            // まずは確定済みのものの状態遷移処理
            rep(j, 149) {
                dp[i][j + 1][1] += 9 * dp[i - 1][j][1]; // 第i桁目が0以外のもの
                dp[i][j][1] += dp[i - 1][j][1]; // 第i桁目が0のもの
            }
            // 次に未確定状態のものの状態遷移処理
            if (pivot == 0) { // 第i桁目が0の場合
                rep(j, 149) {
                    dp[i][j][0] = dp[i - 1][j][0]; // 未確定状態をそのまま持ち越し
                }
            } else { // 第i桁目が0以外の場合
                rep(j, 149) {
                    dp[i][j][1] += dp[i - 1][j][0]; // 第i桁目が0のものは0以外の個数がそのままで確定
                    dp[i][j + 1][1] += (pivot - 1) * dp[i - 1][j][0]; // 第i桁目が 1,2,3,..,pivot-1 のものは0以外の個数が増えて確定
                    dp[i][j + 1][0] += dp[i - 1][j][0]; // 第i桁目が pivot のものは0以外の個数が増えて未確定
                }
            }
        }
    }
    auto ans = dp[len - 1][k][0] + dp[len - 1][k][1];
    PUTS(ans);
}
