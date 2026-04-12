#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; 
    vector<long long> dp(n, (long long)-2e18);
    dp[0] = 0;
    vector<queue<pair<int, long long>>> q(2);
    for (int i = 0; i < n; i++)
    {
        int rem = n / 2 - (n - i) / 2;
        for (int j = 3; j >= - 2; j--)
        {
            if (rem + j < 0) continue;
            if (rem + j + 1 >= n) continue;
            if (dp[rem + j + 1] < dp[rem + j] + a[i])
            {
                int y;
                long long z;
                y = rem + j + 1;
                z = dp[rem + j] + a[i];
                q[i % 2].push({y, z});
            }
        }
        while (q[!(i % 2)].size())
        {
            int y;
            long long z;
            y = q[!(i % 2)].front().first; z = q[!(i % 2)].front().second; q[!(i % 2)].pop();
            dp[y] = max(dp[y], z);
        }
    }
    while (q[0].size())
    {
        int y;
        long long z;
        y = q[0].front().first; z = q[0].front().second; q[0].pop();
        dp[y] = max(dp[y], z);
    }
    while (q[1].size())
    {
        int y;
        long long z;
        y = q[1].front().first; z = q[1].front().second; q[1].pop();
        dp[y] = max(dp[y], z);
    }
    cout << dp[n / 2] << endl;
}