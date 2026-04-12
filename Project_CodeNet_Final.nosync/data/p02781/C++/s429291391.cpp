#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < b; i++)
#define print(a) cout << (a) << endl; 

int dp[101][4][2];

int main() {
    string s; 
    int k;
    cin >> s;
    cin >> k;
    int n = s.size();
    int ret = 0;
    int i0 = s[0] - '0';
    dp[0][1][1] = 1;
    dp[0][1][0] = i0 - 1;
    dp[0][0][1] = 0;
    dp[0][0][0] = 1;

    rep(i, 1, n) {
        int is = s[i] - '0';
        dp[i][0][1] = 0;
        dp[i][0][0] = 1; 
        if (is > 0) {
            rep(k, 1, 4) {
                dp[i][k][0] = dp[i-1][k-1][0] * 9 
                    + dp[i-1][k][0] + dp[i-1][k-1][1] * (is-1) + dp[i-1][k][1]; 
                dp[i][k][1] = dp[i-1][k-1][1]; 
            }
        } else {
            rep(k, 1, 4) {
                dp[i][k][0] = dp[i-1][k][0] + dp[i-1][k-1][0]*9; 
                dp[i][k][1] = dp[i-1][k][1]; 
            } 
        }
    }
    cout << dp[n-1][k][0] + dp[n-1][k][1] << endl;

    return 0;
}