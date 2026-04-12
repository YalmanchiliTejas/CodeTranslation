#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int dp[3002][3002], a[3002];
int add(int a, int b){
    return (a+b)%mod;
}
int main(){
    int n, s;
    scanf("%d%d", &n, &s);   
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    dp[0][0] = 1;
    
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=s;j>=0;j--){
            if(j+a[i] <= s) dp[i][j+a[i]] = add(dp[i][j+a[i]], dp[i-1][j]);
            dp[i][j] = add(dp[i][j], dp[i-1][j]);
        }
        dp[i][0] = add(dp[i][0], 1);
        ans = (ans + dp[i][s])%mod;
    }
    printf("%d\n", ans);
}