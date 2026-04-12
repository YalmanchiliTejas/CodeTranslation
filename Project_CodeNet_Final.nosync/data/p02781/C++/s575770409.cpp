#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
ll dp[105][2][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    
    dp[0][1][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int x = 0; x < 10; ++x){
            int num = s[i] - '0';
            if(x == 0){
                for(int j = 0; j <= 3; ++j){
                    dp[i + 1][0][j] += dp[i][0][j];
                    if(x == num)    dp[i + 1][1][j] += dp[i][1][j];
                    else    dp[i + 1][0][j] += dp[i][1][j];
                }
            }
            else{
                if(x < num){
                    for(int j = 0; j < 3; ++j){
                        dp[i + 1][0][j + 1] += dp[i][0][j];
                        dp[i + 1][0][j + 1] += dp[i][1][j];
                    }
                }
                else if(x == num){
                    for(int j = 0; j < 3; ++j){
                        dp[i + 1][0][j + 1] += dp[i][0][j];
                        dp[i + 1][1][j + 1] += dp[i][1][j];
                    }
                }
                else{
                    for(int j = 0; j < 3; ++j){
                        dp[i + 1][0][j + 1] += dp[i][0][j];
                    }
                }
            }
        }
    }
    ll ans = dp[n][0][k] + dp[n][1][k];
    cout << ans << endl;
}