#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, s;
    long long mod = 998244353;
    cin >> n >> s;
    vector<long long>v(n + 3);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    long long dp[n + 3][s + 3];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= s; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i][0] = i + 1;
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = v[i]; j <= s; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i]]) % mod;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= n; i++){
        ans = (ans + dp[i][s]) % mod;
    }
    cout << ans;
    return 0;
}