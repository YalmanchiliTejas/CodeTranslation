#include <bits/stdc++.h>

using namespace std;
const int N = 3005;
long long dp[N][N],v[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> v[i];
        dp[i][i] = v[i];
    }
    for (int i = n-1; i>=1; i--)
        for (int j = i+1; j<=n; j++)
            dp[i][j] = max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
    cout << dp[1][n];
}
