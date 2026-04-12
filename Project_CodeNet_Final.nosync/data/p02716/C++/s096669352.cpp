#include <bits/stdc++.h>
using namespace std;

// 隣り合わないようにN/2個選択する時，結構ピチピチであるという観察
// i個目までの数字を交互に取る（偶数個目を取る）ことをベースにして，イレギュラーに数字をスキップするのは高々2回まで
// dp[i][j]: i個目までの数字を，イレギュラーに数字をj回スキップしつつ，交互に取るときの，選んだ数字の総和の最大値

const long long INF = 1e18;

long long dp[200005][4];

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k = 1 + n%2; // イレギュラーに数字をスキップできる回数
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0; // 0個目までの数字を，イレギュラーに数字を0回スキップしつつ交互に取るとき，その総和は0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            long long now = dp[i][j];
            if ((i+j) % 2 == 0) {
                now += a[i];
            }
            dp[i+1][j] = max(dp[i+1][j], now);
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}