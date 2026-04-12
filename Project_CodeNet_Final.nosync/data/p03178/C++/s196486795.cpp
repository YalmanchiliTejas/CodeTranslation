#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int dp[110000][110][2];
string K;
int d;

int main() {
    cin >> K >> d;
    int n = K.size();
    dp[0][0][1] = 1;

    for (int i = 1; i<= n; i++) {
        for (int j = 0; j < d; j++) {
            int digit = K[i-1] - '0';
            for (int k = 0; k < 10; k++) {
                dp[i][j][0] += dp[i-1][((j-k)%d+d)%d][0];
                if (k < digit) {
                    dp[i][j][0] += dp[i-1][((j-k)%d+d)%d][1];
                }
                dp[i][j][0] %= MOD;
                dp[i][j][1] = dp[i-1][((j-digit)%d+d)%d][1];
            }
        }
    }
    Int ans = (dp[n][0][0] + dp[n][0][1] + MOD - 1) % MOD;
    cout << ans << endl;
}