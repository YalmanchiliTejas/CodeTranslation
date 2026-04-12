#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

int n;
long long dp[N][2][3];


int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    //scanf("%d", &tc);
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) dp[i][0][j] = dp[i][1][j] = -(1LL << 61);
    }
    while(tc--) {
        scanf("%d", &n);
        int all = (n % 2) + 1;
        bool st = (n / 2) % 2;
        long long ans = dp[1][1][1];
        for(int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if(i - 1 <= all) dp[i][1][i - 1] = x;
            for(int j = 0; j <= all; j++) {
                if(i - 2 - j < 1) break;
                for(int k = 0; k <= all - j; k++) {
                    dp[i][0][j + k] = max(dp[i][0][j + k], dp[i - 2 - j][1][k] + x);
                    dp[i][1][j + k] = max(dp[i][1][j + k], dp[i - 2 - j][0][k] + x);
                }
            }
        }
        for(int i = n - all; i <= n; i++) ans = max(ans, dp[i][st][i - (n - all)]);
        printf("%lld\n", ans);
    }    
    return 0;
}