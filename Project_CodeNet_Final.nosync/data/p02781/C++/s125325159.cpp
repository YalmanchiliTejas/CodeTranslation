#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <numeric>
#include <bitset>
#include <cstdint>
#include <stdexcept>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

// 整数型

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i512 = int512_t;

// [0,n)を昇順/降順でループ

#define rep(i, n) for (int i = 0; i < static_cast<int>(n); ++i)
#define repd(i, n) for (int i = static_cast<int>(n) - 1; i >= 0; --i)

// [a,b)を昇順/降順でループ

#define FOR(i, a, b) for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define FORD(i, a, b) for (int i = static_cast<int>(b) - 1; i >= static_cast<int>(a); --i)

// デバッグ

#ifdef DEBUG
#include <cassert>
#define my_assert(x) assert(x)
#else
#define my_assert(x)
#define assert(x)
#endif

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

map<pair<i512, int>, i512> memo;
i512 loop(i512 n, int k)
{
    if (memo.find({n, k}) != memo.end())
    {
        return memo[{n, k}];
    }
    int n0 = static_cast<int>(n % 10);
    // 0 or (0,n0] or (n0,10)
    auto res1 = loop(n / 10, k); // 0
    auto res2 = k >= 1 ? loop(n / 10, k - 1) : 0; // (0,n0]
    auto res3 = (k >= 1 and n >= 10) ? loop(n / 10 - 1, k - 1) : 0; // (n0,10)
    return memo[{n, k}] = res1 + n0 * res2 + (9 - n0) * res3;
}

int main()
{
    // 高速な入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // 浮動小数の表示の精度
    cout << setprecision(15);

    string s;
    cin >> s;
    i512 n(s);
    int k;
    cin >> k;

    memo[{0, 0}] = 1;
    FOR(i, 1, 4)
    {
        memo[{0, i}] = 0;
    }
    cout << loop(n, k) << endl;

    return 0;
}
