#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    string N;
    int K;
    cin >> N >> K;
    int l = N.size();
    vector<vector<vector<ll>>> dp(l + 1, vector<vector<ll>>(2, vector<ll>(K + 2, 0)));
    dp[0][0][0] = 1;
    rep(i, l) {
        int d = N[i] - '0';
        if (d == 0) {
            dp[i + 1][0][0] = dp[i][0][0];
            dp[i + 1][1][0] = dp[i][1][0];
        } else {
            dp[i + 1][0][0] = 0;
            dp[i + 1][1][0] = 1;
        }
        rep(k, K) {
            if (d == 0) {
                dp[i + 1][0][k + 1] = dp[i][0][k + 1];
                dp[i + 1][1][k + 1] = dp[i][1][k + 1] + dp[i][1][k] * 9; 
            } else {
                dp[i + 1][0][k + 1] = dp[i][0][k];
                dp[i + 1][1][k + 1] = dp[i][1][k] * 9 + dp[i][0][k] * (d - 1) + dp[i][1][k + 1] + dp[i][0][k + 1];
            }
        }
    }
    cout << dp[l][0][K] + dp[l][1][K] << endl;
}