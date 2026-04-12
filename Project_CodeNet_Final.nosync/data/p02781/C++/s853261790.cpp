#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    int64_t K;
    cin >> N;
    cin >> K;
    
    int64_t n = N.size();
    int64_t dp[110][2][4] = {0};
    
    int64_t n0 = N[0] - '0';
    
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[0][1][1] = n0 - 1;
    
    
    for ( int64_t i = 1; i < n; ++i){
        int64_t ni = N[i] - '0';
        if ( ni == 0 ){ // i桁目が0の場合
            // i桁目を0にする
            for ( int64_t j = 0; j <= K; ++j){
                dp[i][0][j] = dp[i][0][j] + dp[i-1][0][j];
            }
        } else { // i桁目が0でない場合
            // i桁目をniにする
            for ( int64_t j = 0; j <= K - 1 ; ++j){
                dp[i][0][j+1] = dp[i][0][j+1] + dp[i-1][0][j];
            }
            // i桁目を(ni>)x(>0)にする
            for ( int64_t j = 0; j <= K - 1 ; ++j){
                dp[i][1][j+1] = dp[i][1][j+1] + ( ni - 1 ) * dp[i-1][0][j];
            }
            for ( int64_t j = 0; j <= K; ++j){
                dp[i][1][j] = dp[i][1][j] + dp[i-1][0][j];
            }
        }
        for ( int64_t j = 0; j <= K; ++j){
            dp[i][1][j] = dp[i][1][j] + dp[i-1][1][j];
        }
        for ( int64_t j = 0; j <= K-1; ++j){
            dp[i][1][j+1] = dp[i][1][j+1] + 9 * dp[i-1][1][j];
        }
    }
    
    cout << dp[n-1][0][K] + dp[n-1][1][K] << endl;
    
    return 0;
}
