#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 3001
ll a[MAXN];
ll dp[MAXN][MAXN];   // i から j　まで
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (n % 2) {
            dp[i][i] = a[i];
        }
        else {
            dp[i][i] = -1 * a[i];
        }
    }
    for (int i = 2; i <= n; i++) {
        // 幅がどれくらいか
        for (int j = 1; j <= n - i + 1; j++) {
            // j　から j + i - 1まで
            if (i % 2 == n % 2) {
                //　先行ターン
                dp[j][j + i - 1] = max(dp[j + 1][j + i - 1] + a[j], dp[j][j + i - 2] + a[j + i - 1]);
            }
            else {
                dp[j][j + i - 1] = min(dp[j + 1][j + i - 1] - a[j], dp[j][j + i - 2] - a[j + i - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}