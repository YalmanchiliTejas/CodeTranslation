#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    string s;
    cin >> s;
    cin >> k;
    string t = "";
    for(i = 0; i < 103 - s.size(); i++) {
        t += '0';
    }
    t += s;
    ll cnt;
    n = t.size();
    ll dp[104][2][4 + 1];
    for(i = 0; i <= 103; i++) {
        for(j = 0; j < 2; j++) {
            for(m = 0; m < 5; m++) {
                dp[i][j][m] = 0;
            }
        }
    }
    //cout << t[102] << endl;
    cnt = 0;
    dp[0][0][0] = 1;
    for(i = 1; i <= 103; i++) {
        if(t[i - 1] != '0') {
            cnt++;
            if(cnt < k + 1) {
                dp[i][0][cnt] += dp[i - 1][0][cnt - 1];
                dp[i][1][cnt] += max(0ll, (ll)(t[i - 1] - '0' - 1)) * dp[i - 1][0][cnt - 1];
                dp[i][1][cnt - 1] += dp[i - 1][0][cnt - 1];
            }
        } else {
            if(cnt <= k) {
                dp[i][0][cnt] += dp[i - 1][0][cnt];
            }
        }
        dp[i][1][0] += dp[i - 1][1][0];
        dp[i][1][1] += dp[i - 1][1][1];
        dp[i][1][1] += dp[i - 1][1][0] * 9;
        dp[i][1][2] += dp[i - 1][1][2];
        dp[i][1][2] += dp[i - 1][1][1] * 9;
        dp[i][1][3] += dp[i - 1][1][3];
        dp[i][1][3] += dp[i - 1][1][2] * 9;
        
        for(j=0;j<min(cnt,k+1);j++){
            dp[i][0][j]+=dp[i-1][0][j];
        }
    }
    cout << dp[103][0][k] + dp[103][1][k] << endl;
    return 0;
}