#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, v[3002];
long long dp[3002][3002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    for(int i = n; i >= 1; --i)
        for(int j = i+1; j <= n+1; ++j)
            dp[i][j] = max(v[i] - dp[i+1][j], v[j-1] - dp[i][j-1]);
    cout << dp[1][n+1] << '\n';
    return 0;
}
