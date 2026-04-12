#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

string n;
int k;

int dp[107][5][2];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int l = n.length();

    dp[0][0][0] = 1;

    for(int i = 0; i < l; ++i) {
        int dig = n[i] - '0';
        for(int j = 0; j <= k; ++j) {
            if(dig == 0) {
                dp[i+1][j][0] += dp[i][j][0];
            } else {
                dp[i+1][j][1] += dp[i][j][0];
            }
            dp[i+1][j][1] += dp[i][j][1];
            if(j < k) {
                for(int d = 1; d <= 9; ++d) {
                    dp[i+1][j+1][1] += dp[i][j][1];
                    if(dig == d) {
                        dp[i+1][j+1][0] += dp[i][j][0];
                    } else if(d < dig) {
                        dp[i+1][j+1][1] += dp[i][j][0];
                    }
                }
            }
        }
    }

    int ans = dp[l][k][0] + dp[l][k][1];
    cout << ans << '\n';
    
    return 0;
}
