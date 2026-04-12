#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 1; i <= (n); ++i)
#define rag(con) std::begin(con), std::end(con)

int main()
{
    int n;

    std::cin >> n;

    std::vector<ll> dat(n);

    std::vector<std::vector<ll>> s(n + 1), t;

    rep(i, n)
    {
        s[i].resize((n - 2) / i + 1);
    }
    t = s;

    rep(i, n)
    {
        std::cin >> dat[i - 1];
    }

    rep(i, n)
    {
        rep(j, (n - 2) / i)
        {
            s[i][j] = s[i][j - 1] + dat[j * i];
            t[i][j] = t[i][j - 1] + dat[n - 1 - j * i];
        }
    }

    ll ans = 0;

    rep(i, n)
    {
        for (int j = 1; j <= (n - 2) / i; ++j)
        {
            int a = n - 1 - i * j;
            if (a <= i)
                break;
            if (a % i > 0 || 2 * (i * j + 1) <= n)
                ans = std::max(ans, s[i][j] + t[i][j]);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}