#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

ll dp[102][2][4];

int main() {
    string N;
    cin >> N;
    int D = N.size();
    int K;
    cin >> K;

    dp[0][0][K] = 1;
    for (int i=0; i<D; ++i) {
        for (int j=0; j<2; ++j) {
            for (int k=0; k<=K; ++k) {
                if (j == 0) {
                    // 一致 -> 一致
                    if (N[i] == '0') {
                        dp[i+1][j][k] += dp[i][j][k];
                    } else {
                        if (k > 0) {
                            dp[i+1][j][k-1] += dp[i][j][k];
                        }
                    }
                    // 一致 -> 未満
                    if (N[i] == '0') {
                        // pass
                    } else {
                        if (k > 0) {
                            dp[i+1][1][k-1] += dp[i][j][k] * (N[i] - '1');
                        }
                        dp[i+1][1][k] += dp[i][j][k];
                    }
                } else {
                    // 未満 -> 未満
                    if (k > 0) {
                        dp[i+1][j][k-1] += dp[i][j][k] * 9;
                    }
                    dp[i+1][j][k] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[D][0][0] + dp[D][1][0] << endl;

    return 0;
}