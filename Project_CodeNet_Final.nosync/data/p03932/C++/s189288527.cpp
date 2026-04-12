#include<bits/stdc++.h>

using namespace std;

const int N = 210;
typedef long long LL;

LL dp[N*2][N][N];
int n, m, mat[N][N];

void mv(int x1, int y1, int x2, int y2, LL v){
    int len = x1 + y1;
    if(x1==x2){
        if(x1==n-1 && y1==m-1){
            dp[len][x1][x2] = max(dp[len][x1][x2], v);
        }
        return;
    }
    dp[len][x1][x2] = max(dp[len][x1][x2], v + mat[x1][y1] + mat[x2][y2]);
}

int main(){
    while(~scanf("%d %d", &n, &m)){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%d", &mat[i][j]);
            }
        }
        LL ans = mat[0][0] + mat[n-1][m-1];
        mat[0][0] = mat[n-1][m-1] = 0;
        memset(dp, -1, sizeof(dp));
        dp[0][0][0] = 0;
        int len = n + m - 2;
        int x1, y1, x2, y2;
        for(int i=0; i<len; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(dp[i][j][k] == -1)   continue;
                    x1 = j;
                    y1 = i - j;
                    x2 = k;
                    y2 = i - k;
                    mv(x1+1, y1, x2+1, y2, dp[i][j][k]);
                    mv(x1+1, y1, x2, y2+1, dp[i][j][k]);
                    mv(x1, y1+1, x2+1, y2, dp[i][j][k]);
                    mv(x1, y1+1, x2, y2+1, dp[i][j][k]);
                }
            }
        }
        printf("%lld\n", ans + dp[len][n-1][n-1]);
    }
    return 0;
}
