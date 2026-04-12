#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int, LL> dp[200002];
int a[200002];
int main(){
    int n;
    scanf("%d", &n);   
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        int mn = i/2, mx = (i+1)/2;
        for(int j=mn;j<=mx;j++){
            dp[i][j] = -1e18;
            for(int k=i-2;k>=max(0, i-5);k--){
                if(dp[k].find(j-1) != dp[k].end()){
                    dp[i][j] = max(dp[i][j], dp[k][j-1] + a[i]);
                }
            }
        }
        for(int j=mn;j<=mx;j++){
            if(dp[i-1].find(j) != dp[i-1].end()){
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        if(i == 1) dp[i][1] = a[i];
    }
    printf("%lld\n", dp[n][n/2]);
}