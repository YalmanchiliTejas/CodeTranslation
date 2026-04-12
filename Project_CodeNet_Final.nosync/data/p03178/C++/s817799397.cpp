#include <bits/stdc++.h>
using namespace std;
// look at 0 - K and subtract 1.

string k;
int n, d;
const int MOD = 1e9 + 7;

// dp[i][j]: if we have i 0-9 choices and we want j mod d, how many ways?
int dp[10002][101];

// solve: int i is the first letter index of the suffix we look at. left is the modulus mod D we want.
long long solve(int i, int left)
{
    if (i == n)
    {
        // base case
        return (left == 0);
    }
    long long ret = 0;
    // take the first char
    ret += solve(i + 1, ((left - (k[i] - '0')) % d + d) % d);

    for (int c = 0; c < (k[i] - '0'); c++)
    {
        ret += dp[n - i - 1][((left - c) % d + d) % d];
        ret %= MOD;
    }

    ret %= MOD;
    return ret;
}

int main()
{
    cin >> k >> d;      
    n = k.length();

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int ret = 0;
            for (int c = 0; c < 10; c++)
            {
                ret += dp[i - 1][((j - c) % d + d) % d];
                ret %= MOD;
            }
            dp[i][j] = ret;
        }
    }

    cout << ((solve(0, 0) - 1) % MOD + MOD) % MOD << endl;
}