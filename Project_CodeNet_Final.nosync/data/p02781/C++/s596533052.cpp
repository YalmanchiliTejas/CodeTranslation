#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll dp[105][2][105];

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    dp[0][0][0] = 1;
    rep(i,n) rep(j,n){
        dp[i+1][1][j+1] += dp[i][1][j] * 9;
        dp[i+1][1][j] += dp[i][1][j];

        int ni = (s[i] - '0');

        if(ni > 0){
            dp[i+1][1][j+1] += dp[i][0][j] * (ni - 1);
            dp[i+1][1][j] += dp[i][0][j];
        }
        
        if(ni > 0){
            dp[i+1][0][j+1] = dp[i][0][j];
        }
        else{
            dp[i+1][0][j] = dp[i][0][j];
        }
    }

    ll ans = dp[n][0][k] + dp[n][1][k];
    cout << ans << endl;
}