#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n, m;
    cin >> s >> m;
    n = s.length();
    
    long long dp[110][2][5] = {0};
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        const int c = s[i] - '0';
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= m; k++) {
                for (int d = 0; d <= (j ? 9 : c); d++) {
                    dp[i+1][j || (d < c)][(d == 0) ? k : k+1] += dp[i][j][k];
                }
            }
        }
    }
    
    long long ans = dp[n][0][m] + dp[n][1][m];
    cout << ans << endl;
    return 0;
}