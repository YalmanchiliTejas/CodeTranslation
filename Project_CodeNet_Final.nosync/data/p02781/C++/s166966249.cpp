#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string N;
    int K;
    cin >> N >> K;
    int d = (int)N.size();
    vector<vector<vector<ll>>> dp(d, vector<vector<ll>>(K+1, vector<ll>(2, 0)));
    vector<int> n(d);
    for (int i = 0; i < d; i++) n[i] = N[i] - '0';
    dp[0][1][0] = n[0]-1;
    dp[0][1][1] = 1;
    for (int i = 1; i < d; i++) dp[i][1][0] = 9;
    for (int i = 1; i < d; i++){
        for (int j = 1; j <= K; j++) {
            if (n[i] > 0) {
                dp[i][j][1] += dp[i-1][j-1][1];
                dp[i][j][0] += dp[i-1][j][1] + dp[i-1][j-1][1] * (n[i]-1) + dp[i-1][j][0] + dp[i-1][j-1][0]*9;
            }else {
                dp[i][j][1] += dp[i-1][j][1];
                dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j-1][0] * 9;
            }
        }
    }
    cout << dp[d-1][K][0] + dp[d-1][K][1] << endl;
    return 0;
}
