#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll dp[105][5][2];

int main() {
    string N; cin >> N;
    int K; cin >> K;
    int n = N.size();
    dp[0][0][0] = 1;
    rep(i, n){
        int x = N[i] - '0';
        rep(j, 10){
            if(j == 0){
                if(N[i] == '0'){
                    rep(k, K+1){
                        dp[i+1][k][0] += dp[i][k][0];
                        dp[i+1][k][1] += dp[i][k][1];
                    }
                } else {
                    rep(k, K+1){
                        dp[i+1][k][1] += dp[i][k][0] + dp[i][k][1];
                    }
                }
            } else if (j < x){
                rep(k, K+1){
                    dp[i+1][k+1][1] += dp[i][k][0] + dp[i][k][1];
                }
            } else if (j == x){
                rep(k, K+1){
                    dp[i+1][k+1][0] += dp[i][k][0];
                    dp[i+1][k+1][1] += dp[i][k][1];
                }
            } else {
                rep(k, K+1){
                    dp[i+1][k+1][1] += dp[i][k][1];
                }
            }
        }    
    }

    cout << dp[n][K][0] + dp[n][K][1] << endl;

    return 0;
}