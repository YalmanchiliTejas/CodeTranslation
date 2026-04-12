#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e4 + 10, maxl = 110, mod = 1e9 + 7;
int dp[maxn][maxl], d;
string s;

signed main()
{
    ios::sync_with_stdio(false);
    cin >> s >> d;

    dp[0][0] = 1;
    for (int i = 0; i < maxn - 5; i++)
        for (int j = 0; j < d; j++)
            for (int x = 0; x < 10; x++)
                (dp[i + 1][(j + x) % d] += dp[i][j]) %= mod;

    int ans = 0;
    for (int i = 0, S = 0; i <= s.size(); S += s[i++] - '0')
    {
        if (i == s.size())
        {
            ans += S % d == 0;
            continue;
        }
        int x = s[i] - '0';
        for (int now = 0; now < x; now++)
            (ans += dp[s.size() - i - 1][(maxn * d - now - S) % d]) %= mod;
    }

    cout << (ans - 1 + mod) % mod;

    return 0;
}
