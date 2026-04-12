#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;

ll dp[105][2][5];
int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    dp[0][1][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int k = 0; k <= 3; k++) {
            for(int j = 0; j < 10; j++) {
                int e = (j != 0);
                int aa = s[i] - '0';
                if(j == aa) {
                    dp[i+1][1][k+e] += dp[i][1][k];
                } else if(j < aa) {
                    dp[i+1][0][k+e] += dp[i][1][k];
                }
                dp[i+1][0][k+e] += dp[i][0][k];
            }
        }
        // for(int j = 0; j < 2; j++) {
        //     for(int k = 0; k < 3; k++) {
        //         printf("dp[%d][%d][%d]:%lld\n", i+1, j, k, dp[i+1][j][k]);
        //     }
        // }
    }
    cout << dp[n][0][k] + dp[n][1][k] << '\n';
    return 0;
}