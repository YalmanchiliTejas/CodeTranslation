#include <bits/stdc++.h>
using namespace std;
#define N 200050
#define K 105
const int MOD = 1e9+7;
int dp[N][K][2] ;
char s[N] ;
int a[N] ;
int n, m ;

int dfs(int k, int now, int lim) {
    if (dp[k][now][lim] >= 0) return dp[k][now][lim] ;
    if (k == m) return dp[k][now][lim] = (now == 0) ;
    int sum = 0, up = lim ? a[k] : 9 ;
    for (int i = 0; i <= up; i++) {
        sum += dfs(k + 1, (now - i + n) % n, lim && i == up) ;
        if (sum >= MOD) sum -= MOD ;
    }
    return dp[k][now][lim] = sum ;
}

signed main(){
    scanf("%s%d", s, &n) ;
    m = strlen(s) ;
    for (int i = 0; i < m; i++) a[i] = s[i] - '0' ;
    for(int i = 0; i < N; i++)
        for(int j = 0; j <  K; j++)
            for(int k = 0; k < 2; k++)
                dp[i][j][k]=-1;
    printf("%d\n", (dfs(0, 0, 1) + MOD - 1) % MOD) ; // 0 is incorrect
    return 0 ;
}
