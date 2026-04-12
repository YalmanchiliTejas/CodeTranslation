#include "bits/stdc++.h"
using namespace std;

int N;
long long a[3005];
long long dp[3005][3005];

// dp[i][j] = optimal values of (X-Y) for seq a = [ai...aj]

long long rec(int i, int j, int turn)
{
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j)
    {
        if (turn == 0)
            return dp[i][j] = a[i];
        else
            return dp[i][j] = -a[i];
    }

    if (turn == 0)
        return dp[i][j] = max(rec(i + 1, j, 1) + a[i], rec(i, j - 1, 1) + a[j]);
    else
        return dp[i][j] = min(rec(i + 1, j, 0) - a[i], rec(i, j - 1, 0) - a[j]);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    long long ans = rec(0, N - 1, 0);
    cout << ans << endl;
    return 0;
}