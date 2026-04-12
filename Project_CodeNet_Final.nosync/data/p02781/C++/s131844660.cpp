#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
Int mod = 1e9+7;
//Int mod = 998244353;

Int dp[101][5];

int main() {
    string s;
    Int k;
    cin >> s >> k;
    dp[0][0] = 1;
    Int n = s.size();
    Int cnt = 0;
    for (Int i = 0; i < n; i++) {
        for (Int j = 0; j <= 3; j++) {
            if (dp[i][j] == 0) continue;
            dp[i + 1][j] += dp[i][j];
            if (j == cnt) {
                dp[i + 1][j + 1] += (dp[i][j] - 1) * 9 + (s[i] - '0');
            }
            else {
               
                dp[i + 1][j + 1] += dp[i][j] * 9;
            }
        }
        if (s[i] != '0') {
            cnt++;
        }
    }
    // for (Int i = 0; i <= n; i++) {
    //     for (Int j = 0; j < 3; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    //}
    dump(dp[n][k]);
    return 0;
}
