#pragma region Header
#include <cstdint>
#include <cmath>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <string>
#include <functional>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < static_cast<int>(n); ++i)
#define repd(i, n) for (int i = static_cast<int>(n) - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = static_cast<int>(a); i <= static_cast<int>(b); ++i)
#define FORD(i, a, b) for (int i = static_cast<int>(b); i >= static_cast<int>(a); --i)
template <typename T>
int SZ(T const &x)
{
    return static_cast<int>(x.size());
}
template <class T>
bool chmax(T &a, T const &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, T const &b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<int> cards(3 * n);
    rep(i, 3 * n)
    {
        cin >> cards[i];
        --cards[i];
    }

    vector dp1(n, vector(n, -1));
    auto dp2 = 0;
    vector dp3(n, -1);
    auto lazy = 0;
    stack<tuple<int, int, int>> up;
    {
        auto x = cards[0], y = cards[1];
        dp1[x][y] = dp1[y][x] = 0;
        dp3[x] = dp3[y] = 0;
    }
    FOR(i, 1, n - 1)
    {
        auto a = cards[3 * i - 1], b = cards[3 * i], c = cards[3 * i + 1];

        if (a == b and b == c)
        {
            ++lazy;
            continue;
        }

        auto solve = [&]() {
            up.emplace(b, c, max(1 + dp1[a][a], dp2));

            rep(x, n)
            {
                up.emplace(c, x, dp3[x]);
                if (a == b and dp1[a][x] >= 0)
                {
                    up.emplace(c, x, 1 + dp1[a][x]);
                }
            }
        };

        solve();
        swap(a, b);
        swap(b, c);
        solve();
        swap(a, b);
        swap(b, c);
        solve();

        while (not up.empty())
        {
            auto [x, y, d] = up.top();
            up.pop();

            chmax(dp1[x][y], d);
            chmax(dp1[y][x], d);
            chmax(dp2, d);
            chmax(dp3[x], d);
            chmax(dp3[y], d);
        }

#ifdef DEBUG
        clog << "dp1\n";
        for (auto &v : dp1)
        {
            for (auto d : v)
            {
                clog << ' ' << d;
            }
            clog << '\n';
        }
        clog << "lazy " << lazy << '\n';
#endif
    }

    auto a = cards[3 * n - 1];
    auto ans = lazy + max(dp2, 1 + dp1[a][a]);
    cout << ans << endl;

    return 0;
}
