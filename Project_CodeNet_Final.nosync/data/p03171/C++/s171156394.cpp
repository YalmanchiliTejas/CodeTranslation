#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long dp[n][n];
    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for(int l = n - 1; l >= 0; l--)
    {
        for(int r = l; r < n; r++)
        {
            if(l == r)
                dp[l][r] = a[l];
            else
            {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }
    printf("%lld\n", dp[0][n - 1]);
    return 0;
}
