#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long dp[N];

int main() {
    int n, k;
    cin >> n >> k;
    long long ans = (long long)n*n;
    if ( k>0 )
        for (int i=n; i>0; i--) {
            ans -= min(i,k)-1;
            int m=n/i;
            ans -= (m-1)*min(i,k);
            ans -= min(n-m*i+1, k);
        }
    cout << ans << '\n';
    return 0;
}
