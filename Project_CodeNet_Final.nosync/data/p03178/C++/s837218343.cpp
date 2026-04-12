#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using ll = long long;
using namespace std;

const ll MOD = 1000000007;

ll dp[10010][100][2];

int main(){
    string s; cin >> s;
    int n = s.length();
    int d; cin >> d;
    
    dp[0][0][0] = 1;
    rep(i,n){
        int num = s[i] - '0';
        rep(j,d){
            rep(k,10) ( dp[i+1][(j+k)%d][1] += dp[i][j][1] ) %= MOD;
            rep(k,num) ( dp[i+1][(j+k)%d][1] += dp[i][j][0] ) %= MOD;
            ( dp[i+1][(j+num)%d][0] += dp[i][j][0] ) %= MOD;
        }
    }
    ll ans = ( dp[n][0][0] + dp[n][0][1] + MOD-1) % MOD;
    cout << ans << endl;
    return 0;
}