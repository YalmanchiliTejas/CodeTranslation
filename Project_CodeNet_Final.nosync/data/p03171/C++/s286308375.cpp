#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;
ll a[3003];
ll dp[3003][3003][2];

ll solve(ll i, ll j, ll turn)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j][turn] != -1)
    {
        return dp[i][j][turn];
    }

    if (turn == 0)
    {
        dp[i][j][turn] = max(a[i] + solve(i + 1, j, 1), a[j] + solve(i, j - 1, 1));
    }
    else
    {
        dp[i][j][turn] = min(solve(i + 1, j, 0), solve(i, j - 1, 0));
    }

    return dp[i][j][turn];
}

int main()
{
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << 2 * solve(0, n - 1, 0) - sum << endl;
    return 0;
}