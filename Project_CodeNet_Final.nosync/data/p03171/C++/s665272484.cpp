#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 3001;
using ll = long long;
int n;
ll arr[N], dp[N][N][2];
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lld",  &arr[i]);
    for(int sz = 1;sz <= n; sz++) {
        for(int i = 0; i < n; i++) {
            int j = i+sz-1;
            if(j >= n) continue;
            if(sz==1) {
                dp[i][j][1] = arr[i];
                dp[i][j][0] = 0;
                continue;            
            }
            for(int k = 1; k >= 0; k--) {
                int x, y;
                if(k==1) {
                    //dp[i][j][1] = max(arr[i]+dp[i+1][j][0], arr[j]+dp[i][j-1][0]);
                    ll h1=0, h2 = 0;
                    h1 = arr[i]+dp[i+1][j][0];
                    h2 = arr[j] + dp[i][j-1][0];
                    if(h1 > h2) {
                        dp[i][j][1] = h1;
                        x = i+1, y = j;
                    }
                    else {
                        dp[i][j][1] =h2;
                        x = i, y = j-1;
                    }
                }
                else {
                    dp[i][j][0] = dp[x][y][1];
                }
            }
        }
    }
    printf("%lld\n", dp[0][n-1][1]-dp[0][n-1][0]);
    return 0;
}