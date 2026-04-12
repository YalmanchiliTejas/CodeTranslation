#include<bits/stdc++.h>
using namespace std;

const int maxn = 3005;

long long dp[maxn][maxn][2];

int a[maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }

    for(int len = 2; len <= n; len++)
    {
        for(int i = 0; i + len - 1 < n ; i++)
        {
            int j = i + len - 1;
            dp[i][j][0] = max(dp[i+1][j][1] + a[i], dp[i][j-1][1] + a[j]);
            dp[i][j][1] = min(dp[i+1][j][0] - a[i], dp[i][j-1][0] - a[j]);
        }
    }

    printf("%lld\n",dp[0][n-1][0]);

    return 0;
}