// 二択を繰り返すDP
// 状態: 区間[i,j), O(N^2)個
// DPの結果: その場合の解
// 遷移: O(1)

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

    int n;
    cin >> n;
    vector<i64> a_s(n);
    rep(i, n) { cin >> a_s[i]; }

    // [i,j)での(先手)-(後手)
    vector dp(n + 1, vector<i64>(n + 1, 0));
    FOR(l, 1, n)
    {
        rep(i, n - l + 1)
        {
            auto j = i + l;
            dp[i][j] = max(a_s[i] - dp[i + 1][j], a_s[j - 1] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n] << '\n';

    return 0;
}
