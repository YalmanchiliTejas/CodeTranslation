#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000007;
char s[10001];
int dp[10001][100][2];

int main() {
    int n, d, i, j, k, l;
    long long ans;
    
    scanf("%s", s);
    scanf("%d", &d);
    
    n = strlen(s);
    
    dp[0][0][0] = 1;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < d; j++) {
            for (k = 0; k < 2; k++) {
                if (dp[i][j][k] == 0) continue;
                
                for (l = 0; l < 10; l++) {
                    if (k == 0 && l > s[i] - '0') break;
                    
                    if (k == 1 || l < s[i] - '0') {
                        dp[i + 1][(j + l) % d][1] += dp[i][j][k];
                        if (dp[i + 1][(j + l) % d][1] >= mod) dp[i + 1][(j + l) % d][1] -= mod;
                    } else {
                        dp[i + 1][(j + l) % d][0] += dp[i][j][k];
                        if (dp[i + 1][(j + l) % d][0] >= mod) dp[i + 1][(j + l) % d][0] -= mod;
                    }
                }
            }
        }
    }
    
    ans = dp[n][0][0] + dp[n][0][1] - 1;
    while (ans < 0) ans += mod;
    while (ans >= mod) ans -= mod;
    
    printf("%lld\n", ans);
    return 0;
}
