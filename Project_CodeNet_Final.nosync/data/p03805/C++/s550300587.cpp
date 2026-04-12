#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf (1e4)
#define pi acos(-1)
using namespace std;

int n, m, dp[1<<8][10];
bool mps[10][10];

int main()
{
    mem(mps, 0);
    scanf("%d%d", &n, &m);
    for(int i = 1, a, b;i <= m;i++)
    {
        scanf("%d%d", &a, &b);
        mps[a][b] = mps[b][a] = 1;
    }
    mem(dp, 0);
    dp[1][1] = 1;
    for(int i = 0;i < (1<<n);i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if((i>>(j - 1))&1)
            {
                for(int k = 1;k <= n;k++)
                {
                    if(!((i>>(k - 1))&1)&&mps[j][k])
                    {
                        int st = i + (1<<(k - 1));
                        dp[st][k] += dp[i][j];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 2;i <= n;i++)
        ans += dp[(1<<n) - 1][i];
    printf("%d\n", ans);
	return 0;
}
