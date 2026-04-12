#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

signed main()
{
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d, vector<int>(2, 0)));
    dp[0][0][1] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < d; ++j){
            for(int k = 0; k < s[i] - '0'; ++k){
                dp[i + 1][(j + k) % d][0] += dp[i][j][1];
                dp[i + 1][(j + k) % d][0] %= MOD;
            }
            dp[i + 1][(j + (s[i] - '0')) % d][1] += dp[i][j][1];
            dp[i + 1][(j + (s[i] - '0')) % d][1] %= MOD;
            for(int k = 0; k < 10; ++k){
                dp[i + 1][(j + k) % d][0] += dp[i][j][0];
                dp[i + 1][(j + k) % d][0] %= MOD;
            }
        }
    }
    cout << (dp[n][0][1] + dp[n][0][0] - 1 + MOD) % MOD << endl;
}
