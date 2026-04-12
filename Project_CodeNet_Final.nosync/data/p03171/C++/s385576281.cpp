#include <bits/stdc++.h>
#define maxn 3005
using namespace std;

long long num[maxn];
long long dp[maxn][maxn];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> num[i];
    for (int i = n; i >= 1; --i)
    {
        for (int j = i; j <= n; ++j)
        {
            dp[i][j] = max(num[i] - dp[i + 1][j], num[j] - dp[i][j - 1]);
        }
    }
    cout << dp[1][n];
    return 0;
}