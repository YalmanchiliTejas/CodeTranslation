#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll dp[200][5][2];

void init(){
    rep(i, 0, 200) rep(j, 0, 5) rep(k, 0, 2) dp[i][j][k] = 0;
}

int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    init();
    dp[0][0][0] = 1;

    rep(i, 0, n) {

        // smaller -> smaller
        rep(j, 0, 3) dp[i+1][j+1][1] += 9*dp[i][j][1];
        rep(j, 0, 4) dp[i+1][j][1] += dp[i][j][1];

        // exact -> smaller
        rep(j, 0, 3) dp[i+1][j+1][1] += max(s[i] - '0' - 1, 0) * dp[i][j][0]; 
        if(s[i] != '0') rep(j, 0, 4) dp[i+1][j][1] += dp[i][j][0]; 

        // exact -> exact
        if(s[i] != '0') rep(j, 0, 4) dp[i+1][j+1][0] += dp[i][j][0];
        else rep(j, 0, 4) dp[i+1][j][0] += dp[i][j][0];

    }

    cout << dp[n][k][0] + dp[n][k][1] << endl;
    return 0;
}