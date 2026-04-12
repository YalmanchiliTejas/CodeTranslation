#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional> // greater など
#include <cmath>      // abs など
#include <numeric>    // accumulate, gcd など
#include <cassert>    // assert
#include <stdexcept>
#include <bitset>
using namespace std;

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
// typedef int128_t ll;
// typedef cpp_int ll;

// GCC, 配列のアクセスなど
#define _GLIBCXX_DEBUG
// Clang, 配列のアクセスなど
#define _LIBCPP_DEBUG 0

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

constexpr inline ll mod = 998244353;
// constexpr int max_n = 200'000 + 5;

int main()
{
    // 高速な入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15); // 浮動小数の表示の精度

    int n, s;
    cin >> n >> s;
    vector<int> as(n);
    rep(i, n) {
        cin >> as[i];
    }

    ll res = 0;
    vector<ll> dp(s+1);
    rep(i, n) {
        int a = as[i];
        if (a > s) {
            continue;
        }
        ll prev = dp[s];
        for (int j = s - a; j >= 1; j--)
        {
            dp[j + a] += dp[j];
            dp[j + a] %= mod;
        }
        dp[a] += i + 1;
        dp[a] %= mod;
        res += (dp[s] - prev + mod) * (n - i) % mod;
        res %= mod;
    }
    cout << res << endl;

    return 0;
}
