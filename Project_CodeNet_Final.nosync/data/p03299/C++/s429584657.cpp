#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
constexpr lint MOD = 1000000007;

int N;
vector<int> h;

lint power(lint x, lint n)
{
    lint ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = ans * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

int main()
{
    cin >> N;
    h.resize(N);
    for (auto &val : h) cin >> val;

    vector<lint> dp(N);
    vector<vector<lint>> dpa(N, vector<lint>(N));
    dp[0] = power(2, h[0]);
    for (int i=0; i<N; i++)
    {
        dpa[0][i] = 2LL * power(2, h[0] - h[i]) % MOD;
    }

    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1] * power(2, h[i] - h[i - 1]);
        dp[i] += dpa[i - 1][i] * power(2, h[i] - h[i - 1]);
        dp[i] %= MOD;
        for (int j = 0; j < N; j++)
        {
            // 前の列の逆
            if (h[i] <= h[i-1])
            {
                if (h[j] < h[i]) dpa[i][j] = dpa[i-1][j];
                else dpa[i][j] = dpa[i-1][i];
            }
            else 
            {
                if (h[i] > h[j])
                {
                    if (h[j] > h[i-1]) dpa[i][j] = dpa[i-1][j] * power(2, h[i] - h[j]);
                    else dpa[i][j] = dpa[i-1][j] * power(2, h[i] - h[i-1]);
                }
                else dpa[i][j] = dpa[i - 1][j];
            }

            // 前の列と同じ
            dpa[i][j] += dpa[i - 1][i] * power(2, h[i] - max(h[i - 1], h[j]));
            dpa[i][j] %= MOD;
        }
    }
    // cout << endl;
    // for (auto vec : dpa)
    // {
    //     for (auto val : vec) cout << val << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto v : dp) cout << v << endl;
    cout << dp[N - 1] << endl;
}
