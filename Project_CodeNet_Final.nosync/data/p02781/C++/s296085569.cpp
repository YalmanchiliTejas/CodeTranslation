#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll dp[200][2][200];

int main(){
    string N;
    ll K;
    cin >> N >> K;

    rep(i, 0, 200){
        rep(j, 0, 2){
            rep(k, 0, 200) dp[i][j][k] = 0;
        }
    }

    // dp[#digits][0:exact, 1:smaller][#digits smaller than or equal to K]

    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    if(N[0] - '0' != 1) dp[1][1][1] = N[0] - '0' - 1; 

    rep(d, 1, N.size()){

        ll D = N[d] - '0';

        // smaller -> smaller
        dp[d+1][1][0] = dp[d][1][0];
        rep(i, 1, K+1){
            dp[d+1][1][i] = 9 * dp[d][1][i-1] + dp[d][1][i];
        }

        // exact -> smaller
        if(D != 0){
            dp[d+1][1][0] += dp[d][0][0];
            rep(i, 1, K+1){
                dp[d+1][1][i] += (D-1) * dp[d][0][i-1] + dp[d][0][i];
            }
        }

        // exact -> exact
        rep(i, 0, K+1){
            if(dp[d][0][i] != 0){
                if(D == 0) dp[d+1][0][i] = dp[d][0][i];
                else dp[d+1][0][i+1] = dp[d][0][i];
            }
        }
    }

    cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
    return 0;
}