#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[3001][3001];
ll n, a[3001];

void solve(ll n, ll m)
{
    // cout << n <<m<<"\n";
    if (dp[n][m]!=-1)
    {
        return;
    }
    else
    {
        dp[n][m]=0;
    }
    if (n==m)
    {
        return;
    }
    if (m==n+1)
    {
        dp[n][m]=a[n];
        return;
    }
    solve(n, m-1);
    solve(n+1, m);
    dp[n][m]=max(a[n]-dp[n+1][m], a[m-1]-dp[n][m-1]);


}

int main()
{

    cin >> n;
    for (int i = 0; i < 3001; ++i)
    {
        for (int j = 0; j < 3001; ++j)
        {
            dp[i][j]=-1;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    solve(0, n);
    cout << dp[0][n];
}