#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
int main() {
    int n, s;
    cin >> n >> s;
    int a[3030];
    long long dp[3030][3030][3];
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= s; j++) {
            (dp[i+1][j][0] += dp[i][j][0]) %= mod;
            (dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
            (dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2]) %= mod;
            if(j + a[i] <= s){
                (dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1]) %= mod;
                (dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1]) %= mod;
            }
        }
    }
    cout << dp[n][s][2] << endl;
}