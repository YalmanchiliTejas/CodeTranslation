#pragma region Header
#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#define IFD(...)
#ifndef NDEBUG
#define NDEBUG
#endif
#endif
#include <utility>
#include <cstdint>
#include <cmath>
#include <cassert>
#include <vector>
#include <array>
#include <deque>
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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <boost/hana/functional/fix.hpp>
using boost::hana::fix;
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, b, a) for (int i = (b); i >= (a); --i)
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

    i64 n;
    cin >> n;
    i64 x, m;
    cin >> x >> m;

    int cyc = 0;
    i64 sum0 = 0;
    i64 sum1 = 0;
    int ini = -1;
    int y1;
    {
        vector<i64> sums(m, -1);
        vector<int> occ(m, -1);
        i64 y = x;
        i64 sum = 0;
        for (int i = 0;; ++i)
        {
            sum += y;

            if (occ[y] >= 0)
            {
                ini = occ[y];
                cyc = i - occ[y];
                sum0 = sums[y];
                sum1 = sum - sums[y];
                y1 = y * y % m;

                break;
            }

            sums[y] = sum;
            occ[y] = i;
            y = y * y % m;
        }
    }
    debug(cyc, sum0, sum1, ini, y1);

    i64 ans = 0;
    if (ini >= n)
    {
        // nが小さいので直接
        i64 y = x;
        rep(i, n)
        {
            ans += y;
            y = y * y % m;
        }
    }
    else
    {
        i64 n2 = n - ini - 1;
        ans += sum0;
        ans += n2 / cyc * sum1;
        n2 %= cyc;

        // y1からn2項
        i64 y = y1;
        rep(i, n2)
        {
            ans += y;
            y = y * y % m;
        }
    }

    cout << ans << '\n';

    return 0;
}
