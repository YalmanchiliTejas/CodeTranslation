#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, len, i, j;
ll t [3001];
ll dp [3001][3001];

int main ()
    {
    scanf ("%d",&n);
    for (i=1; i<=n; i++)
        scanf ("%lld",&dp[i][i]);
    for (len=1; len<n; len++)
        for (i=1; i+len<=n; i++)
            {
            j=i+len;
            dp[i][j]=max(dp[i][i]-dp[i+1][j],dp[j][j]-dp[i][j-1]);
            }
    printf ("%lld\n",dp[1][n]);
    return 0;
    }
