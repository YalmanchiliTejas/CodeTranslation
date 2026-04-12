#include <bits/stdc++.h>
using namespace std;

long long dfs(vector<vector<long long>> &dp, const vector<long long> &a, int l, int r, bool flag, const long long init)
{
    if (dp[l][r] == init)
    {
        long long sign;
        if (flag)
        {
            sign = 1;
        }
        else
        {
            sign = -1;
        }

        if (l == r)
        {
            dp[l][r] = sign * a[l];
        }
        else
        {
            long long left = sign * a[l] + dfs(dp, a, l + 1, r, flag ^ 0x1, init);
            long long right = sign * a[r] + dfs(dp, a, l, r - 1, flag ^ 0x1, init);
            if (flag)
            {
                dp[l][r] = max(left, right);
            }
            else
            {
                dp[l][r] = min(left, right);
            }
        }
    }
    return dp[l][r];
}

int main()
{
    int N;
    cin >> N;

    vector<long long> a(N);
    for (long long &elem : a)
    {
        cin >> elem;
    }

    const long long init = LONG_LONG_MAX;
    vector<vector<long long>> dp(N, vector<long long>(N, init));
    int l = 0;
    int r = N - 1;
    cout << dfs(dp, a, l, r, true, init) << endl;
}
