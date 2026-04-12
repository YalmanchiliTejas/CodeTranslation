#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)

ll dp[100005][2][110];

int main(void){
    string k;
    int d;
    cin >> k >> d;
    
    int n = k.size();
    dp[0][0][0] = 1;
    
    ll ans = 0,mod = 1e9+7;
    for(int i = 0;i < n;i++){
        int a = (k[i] - '0');
        for(int j = 0;j < d;j++){
            for(int l = 0;l < 10;l++){
                dp[i+1][1][(j+l)%d] += dp[i][1][j];
                dp[i+1][1][(j+l)%d] %= mod;
            }
            
            for(int l = 0;l < a;l++){
                dp[i+1][1][(j+l)%d] += dp[i][0][j];
                dp[i+1][1][(j+l)%d] %= mod;
            }
            
            dp[i+1][0][(j+a)%d] += dp[i][0][j];
            dp[i+1][0][(j+a)%d] %= mod;
            
        }
    }
    
    ans = (dp[n][0][0] + dp[n][1][0] - 1 + mod) % mod;
    cout << ans << endl;
}