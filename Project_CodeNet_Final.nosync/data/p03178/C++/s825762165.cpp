#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int d, i, j, l, dp[10003][2][103] = {}, ans;
    string k;

    cin >> k;
    scanf("%d", &d);

    dp[0][0][0] = 1;
    for (i = 0; i < k.size(); i++) {
        for (j = 0; j < d; j++) {
            dp[i + 1][0][(j + k[i] - '0') % d] += dp[i][0][j];
            dp[i + 1][0][(j + k[i] - '0') % d] %= mod;
        }
        for (j = 0; j < d; j++) {
            for (l = 0; l < k[i] - '0'; l++) {
                dp[i + 1][1][(j + l) % d] += dp[i][0][j];
                dp[i + 1][1][(j + l) % d] %= mod;
            }
        }
        for (j = 0; j < d; j++) {
            for (l = 0; l < 10; l++) {
                dp[i + 1][1][(j + l) % d] += dp[i][1][j];
                dp[i + 1][1][(j + l) % d] %= mod;
            }
        }
    }

    ans = (dp[k.size()][0][0] + dp[k.size()][1][0]) % mod;
    ans = (ans + mod - 1) % mod;

    printf("%d\n", ans);

    return 0;
}