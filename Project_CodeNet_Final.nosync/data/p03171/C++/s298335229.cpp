#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int, long long int> P;
P dp[3000][3000][3];
int n;
int a[3000];

P dfs(int l, int r, int t)
{
    if (dp[l][r][t + 1] != P(-1, -1))
    {
        return dp[l][r][t + 1];
    }
    P pl = dfs(l + 1, r, -t);
    P pr = dfs(l, r + 1, -t);
    if (t == 1)
    {
        if (pl.first - pl.second + a[l] < pr.first - pr.second + a[n - r - 1])
        {
            pr.first += a[n - r - 1];
            dp[l][r][t + 1] = pr;
            return pr;
        }
        else
        {
            pl.first += a[l];
            dp[l][r][t + 1] = pl;
            return pl;
        }
    }
    else
    {
        if (pl.first - pl.second - a[l] < pr.first - pr.second - a[n - r - 1])
        {
            pl.second += a[l];
            dp[l][r][t + 1] = pl;
            return pl;
        }
        else
        {
            pr.second += a[n - r - 1];
            dp[l][r][t + 1] = pr;
            return pr;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j][2] = P(-1, -1);
            dp[i][j][0] = P(-1, -1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][n - i - 1][2] = P(a[i], 0);
        dp[i][n - i - 1][0] = P(0, a[i]);
    }
    P p = dfs(0, 0, 1);
    cout << p.first - p.second << endl;
}