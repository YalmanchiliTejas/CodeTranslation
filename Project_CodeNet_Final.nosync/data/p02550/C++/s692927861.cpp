#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rag(con) std::begin(con), std::end(con)

constexpr int MAX = 1e5 + 5, MAXL = 35;

ll vis[MAXL][MAX];
ll sum[MAXL][MAX];

int main()
{
    ll n, x, m;

    std::cin >> n >> x >> m;

    rep(i, m)
    {
        vis[0][i] = i * i % m;
        sum[0][i] = i;
    }

    for (int i = 1; i < MAXL; ++i)
    {
        rep(j, m)
        {
            vis[i][j] = vis[i - 1][vis[i - 1][j]];
            sum[i][j] = sum[i - 1][j] + sum[i - 1][vis[i - 1][j]];
        }
    }

    ll y = 1, ans = x - x % m, now = x % m;

    for (int i = 0; i < MAXL; ++i)
    {

        if (y & (n - 1))
        {
            ans += sum[i][now];
            now = vis[i][now];
        }

        y *= 2;
    }

    std::cout << ans + now << std::endl;

    return 0;
}