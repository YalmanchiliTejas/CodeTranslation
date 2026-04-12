#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e3 + 2;
long long n, nums[mxN], dp[mxN][mxN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int len = 0; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            if (len == 0)
            {
                continue;
            }

            long long t1 = nums[i] + dp[i + 1][len - 1];
            long long t2 = nums[i + len - 1] + dp[i][len - 1];
            if ((len - n) % 2)
            {
                t1 -= 2 * nums[i];
                t2 -= 2 * nums[i + len - 1];
            }

            if ((len - n) % 2 == 0)
            {
                dp[i][len] = max(t1, t2);
            }
            else
            {
                dp[i][len] = min(t1, t2);
            }
        }
    }

    cout << dp[0][n] << endl;
}