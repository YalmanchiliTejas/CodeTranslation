#include <bits/stdc++.h>
using namespace std;

long long solve(size_t n)
{
    vector<long long> A(n + 1, 0);
    for (size_t i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(3, -1e15));
    dp[0][0] = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            {
                // j = 0
                dp[i][0] = max(dp[i][0], dp[i - 1][0]);
            }
            {
                // j = 1
                dp[i][1] = max(dp[i][1], dp[i - 1][1] + A[i]);
                dp[i][2] = max(dp[i][2], dp[i - 1][1]);
            }
            {
                // j = 2
                dp[i][2] = max(dp[i][2], dp[i - 1][2]);
            }
        }
        else
        {
            {
                // j = 0
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + A[i]);
                dp[i][1] = max(dp[i][1], dp[i - 1][0]);
            }
            {
                // j = 1
                dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            }
            {
                // j = 2
                dp[i][2] = max(dp[i][2], dp[i - 1][2] + A[i]);
            }
        }
    }
    if (n % 2 == 0)
    {
        return max(dp[n][0], dp[n][1]);
    }
    else
    {
        return max(dp[n][1], dp[n][2]);
    }
}

int main()
{
    size_t N;
    cin >> N;

    cout << solve(N) << endl;
}
