#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>v(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    if(n % 2 == 0){
        long long dp[n + 3][2];
        dp[1][0] = v[1];
        for(int i = 3; i <= n; i += 2){
            dp[i][0] = dp[i - 2][0] + v[i];
        }
        dp[2][1] = v[2];
        for(int i = 4; i <= n; i += 2){
            dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + v[i];
        }
        cout << max(dp[n][1], dp[n - 1][0]);
    }
    else{
        long long dp[n + 3][3];
        dp[1][0] = v[1];
        for(int i = 3; i <= n; i = i + 2){
            dp[i][0] = dp[i - 2][0] + v[i];
        }
        dp[2][1] = v[2];
        for(int i = 4; i <= n; i = i + 2){
            dp[i][1] = max(dp[i - 2][1], dp[i - 3][0]) + v[i];
        }
        dp[3][2] = v[3];
        for(int i = 5; i <= n; i = i + 2){
            long long val = max(dp[i - 2][2], dp[i - 3][1]);
            dp[i][2] = max(val, dp[i - 4][0]) + v[i];
        }
        long long ans = max(dp[n - 2][0], dp[n - 1][1]);
        ans = max(ans, dp[n][2]);
        cout << ans;
    }
    return 0;
}