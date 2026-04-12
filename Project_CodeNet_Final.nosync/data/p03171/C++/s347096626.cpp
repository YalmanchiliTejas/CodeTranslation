#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[5000][5000];
LL value[5000];

LL cal(LL i, LL j)
{
    if (j < i)
    {
        return 0;
    }

    if (dp[i][j] == -1)
    {

        if (dp[i + 2][j] == -1)
        {
            dp[i + 2][j] = cal(i + 2, j);
        }

        if (dp[i + 1][j - 1] == -1)
        {
            dp[i + 1][j - 1] = cal(i + 1, j - 1);
        }

        if (dp[i][j - 2] == -1)
        {
            dp[i][j - 2] = cal(i, j - 2);
        }

        dp[i][j]=max(value[i]+min(dp[i+2][j],dp[i+1][j-1]),value[j]+min(dp[i+1][j-1],dp[i][j-2]));
    }

    return dp[i][j];
}

int main()
{
    LL i, j, k, n,sum=0;
    for (i = 0; i < 5000; i++)
    {
        for (j = 0; j < 5000; j++)
        {
            dp[i][j] = -1;
        }
    }

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> value[i];
        sum+=value[i];
    }

    LL answer = cal(1, n);

    cout<<2*answer-sum<<endl;
}