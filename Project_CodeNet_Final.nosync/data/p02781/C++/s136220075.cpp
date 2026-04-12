typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    std::cin >> s;
    ll n = s.size();
    ll k;
    std::cin >> k;
    vector<vector<vector<ll>>> dp(n+5,vector<vector<ll>>(k+5,vector<ll>(2,0)));
    dp[0][0][1] = 1;
    
    for (int i = 0; i < n; i++) {
        ll x = s[i]-'0';
        for (int j = 0; j <= k; j++) {
            if(x==0){
                if(j-1>=0)dp[i+1][j][1] = dp[i][j][1];
            }else{
                if(j-1>=0)dp[i+1][j][1] = dp[i][j-1][1];
                if(j-1>=0)dp[i+1][j][0] += dp[i][j-1][1]*(x-1);
                dp[i+1][j][0] += dp[i][j][1];
            }
            if(j-1>=0)dp[i+1][j][0] += dp[i][j-1][0]*9;
            dp[i+1][j][0] += dp[i][j][0];
        }
    }

    std::cout << dp[n][k][0]+dp[n][k][1] << std::endl;
}
