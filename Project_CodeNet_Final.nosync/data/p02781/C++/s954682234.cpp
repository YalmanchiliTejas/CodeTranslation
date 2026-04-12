#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    vector<vector<vector<ll>>> dp(s.size() + 1, vector<vector<ll>>(k + 1, vector<ll>(2, 0)));
    dp[0][0][0] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j][1] += dp[i][j][1];
            if (j - 1 >= 0) {
                dp[i + 1][j][1] += dp[i][j - 1][1] * 9;
                if (s[i] >= '1') {
                    dp[i + 1][j][0] += dp[i][j - 1][0];
                }
                if (s[i] >= '2') {
                    dp[i + 1][j][1] += dp[i][j - 1][0] * (s[i] - '1');
                }
            }
            if (s[i] == '0') {
                dp[i + 1][j][0] += dp[i][j][0];
            }
            else {
                dp[i + 1][j][1] += dp[i][j][0];
            }
        }
    }
    cout << dp[s.size()][k][0] + dp[s.size()][k][1] << endl;
    return 0;
}