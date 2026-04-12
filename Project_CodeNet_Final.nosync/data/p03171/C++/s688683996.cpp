#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> vs(n);
    for (auto& v : vs)
    {
        cin >> v;
    }

    vector<vector<int64_t>> dp(n, vector<int64_t>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = n % 2 == 0 ? -vs[i] : vs[i];
    }

    for (int w = 1; w < n; w++)
    {
        for (int l = 0; l < n - w; l++)
        {
            const int r = l + w;
            if ((n - 1 - w) % 2 == 0)
            {
                dp[l][r] = max(dp[l + 1][r] + vs[l], dp[l][r - 1] + vs[r]);
            }
            else
            {
                dp[l][r] = min(dp[l + 1][r] - vs[l], dp[l][r - 1] - vs[r]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}