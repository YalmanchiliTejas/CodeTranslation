#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    int k;
    cin >> n >> k;

    n += '0';
    reverse(n.begin(), n.end());

    int dp[n.length()][k+1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i < n.length(); i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x <= (j == 0 ? 0 : 9); x++) {
                dp[i][j][0] += dp[i-1][j-!!x][0];
                if (x < n[i] - '0') {
                    dp[i][j][1] += dp[i-1][j-!!x][0];
                } else if (x == n[i] - '0') {
                    dp[i][j][1] += dp[i-1][j-!!x][1];
                }
            }
        }
    }

    cout << dp[n.length()-1][k][1];

    return 0;
}
