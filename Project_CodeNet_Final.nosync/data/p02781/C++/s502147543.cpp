#include <cstring>
#include <cstdio>
#define INF 1e9
#define eps 1e-6
typedef long long ll;
char c[210];
int k, n, dp[110][5][2];
int dfs(int now, int cnt, bool equalN){
    if(now == n + 1)
        return cnt == k;            
    if(cnt > k)                     
        return 0;
    if(dp[now][cnt][equalN] >= 0 && !equalN)   
        return dp[now][cnt][equalN];
    int maxx = equalN ? c[now] - '0' : 9, sum = 0;
    for(int i = 0; i <= maxx; i++) 
        sum += dfs(now + 1, cnt + (i != 0), equalN && (i == maxx));
    return dp[now][cnt][equalN] = sum;
}
int main(){
    memset(dp, -1, sizeof(dp));
    scanf("%s\n%d", c + 1, &k);
    n = strlen(c + 1);
    printf("%d\n", dfs(1, 0, 1));
    return 0;
}