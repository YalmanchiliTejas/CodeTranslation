#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxn = 1e4 + 100, maxl = 110, dig = 10, mod = 1e9 + 7;
ll dp[maxn][maxl], ps[maxn][maxl];

int main()
{
    int d;
    string k;
    cin >> k >> d;

    for (int i = 0; i < maxn - dig; i++)
        for (int j = 0; j < d; j++)
            for (int x = 0; x < dig; x++)
                if (!i)
                    dp[i + 1][j] += (((x % d) == j) && x);
                else
                    dp[i + 1][(j + x) % d] = (dp[i + 1][(j + x) % d] + dp[i][j]) % mod;

    for (int j = 0; j < d; j++)
        for (int i = 1; i < maxn - dig; i++)
            ps[i][j] = (ps[i - 1][j] + dp[i][j]) % mod;

    ll ans = 0;
    for (int i = 0, s = 0, x; i < k.size(); s += x, ans %= mod, i++)
    {
        x = k[i] - '0';

        if (i == k.size() - 1)
            for (int j = 0; j <= x; j++)
                if (j || i)
                    ans += !((s + j) % d);
                else
                    continue;
        else
            for (int j = 0; j < x; ans += ((!((s + j) % d)) && (j || i)) ,j++)
                for (int u = 0; u < d; u++)
                    if (!((u + s + j) % d))
                        ans = (ans + ps[k.size() - i - 1][u]) % mod;
    }

    cout << ans;

    return 0;
}