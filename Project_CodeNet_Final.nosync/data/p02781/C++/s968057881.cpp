#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define ve vector
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)


ll dp[110][5][2];

int main(){
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n){
        int si = s[i] -'0';
        if(si==0){
            rep(j,4){
                dp[i+1][j][0] += dp[i][j][0];
                dp[i+1][j+1][1] += dp[i][j][1] * 9;
                dp[i+1][j][1] += dp[i][j][1];
            }
            continue;
        }
        else{
            rep(j,4){
                dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
                dp[i+1][j+1][1] += dp[i][j][1] * 9 + dp[i][j][0] *(si-1);
                dp[i+1][j+1][0] += dp[i][j][0];
            }
        }
    }
    ll ans = dp[n][k][1] + dp[n][k][0];
    cout << ans << endl;
    return 0;
}