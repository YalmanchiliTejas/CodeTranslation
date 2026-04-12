#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int iinf = 1 << 28;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;

ll dp[101][2][4];

void work() {
    string s; int K; cin>>s>>K;
    int n = s.size();
    dp[n-1][0][0] = 1LL; dp[n-1][0][1] = 9LL; dp[n-1][0][2] = dp[n-1][0][3] = 0LL;
    dp[n-1][1][0] = 1LL; dp[n-1][1][1] = s[n-1] - '0'; dp[n-1][1][2] = dp[n-1][1][3] = 0LL;
    for (int i = n-2; i >= 0; --i) {
        dp[i][0][0] = dp[i+1][0][0];
        dp[i][0][1] = 9LL * dp[i+1][0][0] + dp[i+1][0][1];
        dp[i][0][2] = 9LL * dp[i+1][0][1] + dp[i+1][0][2];
        dp[i][0][3] = 9LL * dp[i+1][0][2] + dp[i+1][0][3];
        dp[i][1][0] = dp[i][1][1] = dp[i][1][2] = dp[i][1][3] = 0LL;
        for (int j = (i == 0 ? 1 : 0); j < s[i] - '0'; ++j) {
            if (j == 0) {
                dp[i][1][0] += dp[i+1][0][0];
                dp[i][1][1] += dp[i+1][0][1];
                dp[i][1][2] += dp[i+1][0][2];
                dp[i][1][3] += dp[i+1][0][3];
            } else {
                dp[i][1][0] += 0LL;
                dp[i][1][1] += dp[i+1][0][0];
                dp[i][1][2] += dp[i+1][0][1];
                dp[i][1][3] += dp[i+1][0][2];
            }
        }
        dp[i][1][0] += (s[i] == '0') ? dp[i+1][1][0] : 0LL;
        dp[i][1][1] += (s[i] == '0') ? dp[i+1][1][1] : dp[i+1][1][0];
        dp[i][1][2] += (s[i] == '0') ? dp[i+1][1][2] : dp[i+1][1][1];
        dp[i][1][3] += (s[i] == '0') ? dp[i+1][1][3] : dp[i+1][1][2];
    }
    cout << dp[0][1][K] + dp[1][0][K] << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    work();
    return 0;
}
