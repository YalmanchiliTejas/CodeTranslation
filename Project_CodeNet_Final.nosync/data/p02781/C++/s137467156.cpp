#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 100; 
const int B = 10; 

char s[N + 5]; 
int n, k; 
int dp[B + 5][5][N + 5]; 

int main() {

    dp[0][0][0] = 1;
    s[0] = '0';
    scanf("%s", s + 1); 
    scanf("%d", &k); n = strlen(s + 1); 
    for (int i = 1, j = n; i < j; i ++, j --)
        std::swap(s[i], s[j]); 

    if (n == 1 && s[n] == '0') {
        printf("%s\n", k == 0 ? "1" : "0");
        return 0;
    }
    
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < B; j ++) 
            for (int x = (j > 0); x <= k; x ++) {
                for (int y = 0; y < B; y ++)
                    dp[j][x][i] += dp[y][x - (j > 0)][i - 1];
            }
    }

    for (int j = 0; j < s[n] - '0'; j ++) 
        for (int x = (j > 0); x <= k; x ++) {
            for (int y = 0; y < B; y ++)
                dp[j][x][n] += dp[y][x - (j > 0)][n - 1];
        }
    
    for (int bb = n - 1, cc = 1; bb >= 0 && cc <= k; bb --) {
        //for (int j = 0; j < s[bb] - '0'; j ++) 
        for (int y = 0; y < s[bb] - '0'; y ++)
            dp[s[n] - '0'][k][n] += dp[y][k - cc][bb];
        if (s[bb] - '0')
            cc ++; 
        if (bb == 0) dp[s[n] - '0'][k][n] += dp[0][k - cc][bb];
    }

    int ans = 0;
    for (int i = 0; i <= s[n] - '0'; i ++) 
        ans += dp[i][k][n];

    printf("%d\n", ans);

    return 0; 
}