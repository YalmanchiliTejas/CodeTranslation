#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 1000;
int fac[MAXN + 1][MAXN + 1];
int invFac[MAXN + 1][MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

int modPow(int b, int e)
{
    int ans = 1;
    while (e > 0)
    {
        if (e & 1)
        {
            ans = (int) (((long long) ans * b) % MOD);
        }
        b = (int) (((long long) b * b) % MOD);
        e >>= 1;
    }
    return ans;
}

int modInv(int x)
{
    return modPow(x, MOD - 2);
}

int main()
{
    fill(fac[0], fac[0] + MAXN + 1, 1);
    fill(invFac[0], invFac[0] + MAXN + 1, 1);
    fac[1][0] = invFac[1][0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fac[1][i] = (int) (((long long) fac[1][i - 1] * i) % MOD);
        invFac[1][i] = modInv(fac[1][i]);
    }
    for (int i = 2; i <= MAXN; i++)
    {
        for (int j = 1; j <= MAXN; j++)
        {
            fac[i][j] = (int) (((long long) fac[i - 1][j] * fac[1][j]) % MOD);
            invFac[i][j] = modInv(fac[i][j]);
        }
    }
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    fill(dp[0], dp[0] + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = a; j <= b; j++)
        {
            dp[i][j] = dp[i][j - 1];
            for (int k = c; k <= d && k * j <= i; k++)
            {
                // temp = num ways to set the last k groups
                int temp = (int) (((long long) fac[1][i] * invFac[1][i - k * j]) % MOD);
                temp = (int) (((long long) temp * invFac[k][j]) % MOD);
                temp = (int) (((long long) temp * invFac[1][k]) % MOD);
                temp = (int) (((long long) temp * dp[i - k * j][j - 1]) % MOD);
                dp[i][j] = dp[i][j] + temp;
                if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][b] << endl;
    return 0;
}
