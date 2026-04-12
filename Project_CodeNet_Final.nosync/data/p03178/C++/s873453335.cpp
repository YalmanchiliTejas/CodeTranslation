#include <bits/stdc++.h>

#define N_MAX 10002
#define D_MAX 102
#define ll long long

using namespace std;

const ll MOD = 1e9+7;

int n;

int k[N_MAX];

int d;

ll dp[N_MAX][D_MAX][2];

int modd (int a, int b)
{
    return (a % d - b % d + d) % d;
}

int main()
{
    string s;
    cin >> s;
    n = s.size();
    for(int i = 1; i <= n; i++)
        k[i] = s[n - i] - '0';
    cin >> d;
    dp[0][0][true] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < d; j++)
        {
            for(int c = 0; c <= 9; c++)
            {
                if(c > k[i])
                    dp[i][j][false] += dp[i - 1][modd(j, c)][false] + dp[i - 1][modd(j, c)][true];
                if(c < k[i])
                    dp[i][j][true] += dp[i - 1][modd(j, c)][false] + dp[i - 1][modd(j, c)][true];
                if(c == k[i])
                {
                    dp[i][j][false] += dp[i - 1][modd(j, c)][false];
                    dp[i][j][true] += dp[i - 1][modd(j, c)][true];
                }
            }
            dp[i][j][false] %= MOD;
            dp[i][j][true] %= MOD;
        }
    cout << (dp[n][0][true] - 1 + MOD) % MOD << "\n";
    return 0;
}
