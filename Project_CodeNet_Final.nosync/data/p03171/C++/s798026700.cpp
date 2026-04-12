#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (ll &i: a) scanf("%lld", &i);
    vector<vector<ll>> dp(n+5, vector<ll>(n+5));
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<n; j++) {
            if (j<i) dp[i][j] = 0;
            else if (j==i) {
                if (n&1) dp[i][j] = a[i];
                else dp[i][j] = -a[i];
            } else if ((n-(j-i+1)) & 1) {
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j]);
                
            } else {
                dp[i][j] = max(a[i]+dp[i+1][j], a[j]+dp[i][j-1]);
            }
        }
    }

    printf("%lld\n", dp[0][n-1]);
}