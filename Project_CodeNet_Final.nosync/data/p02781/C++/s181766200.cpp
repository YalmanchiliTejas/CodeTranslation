#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    string N;
    int K;
    cin >> N >> K;
    int l = N.size();
    // dp[i][j][0] 上からi+1桁で０でない数がj個でN未満確定
    // dp[i][j][1] 上からi+1桁で０でない数がj個でNと一致
    vector<vector<vector<int>>> dp(l, vector<vector<int>>(K + 2, vector<int>(2, 0)));
    dp[0][0][0] = 1;
    dp[0][1][0] = N[0] - '1';
    dp[0][1][1] = 1;
    rep(i, l - 1) {
        rep(j, K + 1) {
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j + 1][0] += dp[i][j][0] * 9;
            if (N[i + 1] == '0') {
                dp[i + 1][j][1] += dp[i][j][1];
            } else {
                dp[i + 1][j + 1][1] += dp[i][j][1];
                dp[i + 1][j + 1][0] += dp[i][j][1] * (N[i + 1] - '1') + dp[i][j + 1][1];
            }
        }
    }
    cout << dp[l - 1][K][0] + dp[l - 1][K][1] << "\n";
    /*
    rep(i, l) {
        rep(j, K + 2) {
            rep(k, 2) {
                cout << " dp[" << i << "][" << j << "][" << k << "]=" << dp[i][j][k]; 
            }
        }
        cout << "\n";
    }
    */
}