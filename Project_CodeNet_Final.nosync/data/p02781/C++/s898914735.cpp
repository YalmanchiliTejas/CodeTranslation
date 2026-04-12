#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)

ll dp[1005][2][1005];

int main(void){
    string s;
    int k;
    cin >> s >> k;
    
    int n = s.size();
    dp[0][0][0] = 1;
    
    for(int i = 0;i < n;i++){
        int a = s[i]-'0';
        for(int j = 0;j < k;j++){
            dp[i+1][1][j] += dp[i][1][j];
            for(int l = 1;l < 10;l++){
                dp[i+1][1][j+1] += dp[i][1][j];
            }
            
            for(int l = 1;l < a;l++){
                dp[i+1][1][j+1] += dp[i][0][j];
            }
            
            if(a == 0)dp[i+1][0][j] += dp[i][0][j];
            else dp[i+1][0][j+1] += dp[i][0][j];
            if(a > 0)dp[i+1][1][j] += dp[i][0][j];
        }
    }
    
    ll ans = 0;
    rep(i,n)ans += (dp[i+1][1][k] + dp[i+1][0][k]);
    cout << ans << endl;
}