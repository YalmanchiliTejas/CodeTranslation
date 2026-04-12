#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long

const int N = 5007, inf = 1e18;
int n, a[N], dp[N][N];

int rec(int l, int r)
{
    if (dp[l][r] != -inf)
        return dp[l][r];
    dp[l][r] = max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));
    return dp[l][r];
}

void preset()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            dp[i][j] = -inf;
        }
    }
}

signed main()
{
    fastio;
    preset();
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = a[i];
    }
    cout << rec(0, n - 1);
    return 0;
}

/* input

*/