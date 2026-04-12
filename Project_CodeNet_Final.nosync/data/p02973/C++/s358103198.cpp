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

// #define NDEBUG 1
// debug用出力 https://trap.jp/post/998/
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << H << " ";
    debug_out(T...);
}
#ifdef NDEBUG
#define debug(...)
#else
#define debug(...) debug_out(__VA_ARGS__)
#endif

//////////////// //////////////// //////////////// //////////////// ////////////////
//////////////// //////////////// //////////////// //////////////// ////////////////

int n;
vector<int> as;
int dp;
multiset<int> dp2;

int main()
{
    // 高速な入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15); // 浮動小数の表示の精度

    cin>>n;
    rep(i,n) {
        int a; cin>>a; as.push_back(a);
    }

    // これも嘘かも
    rep(i, n) {
        int a = as[i];
        if (dp2.empty()) { dp++; dp2.insert(a); continue; }
        auto it = dp2.lower_bound(a);
        if (it == dp2.begin()) { dp++; dp2.insert(a); }
        else { it--; dp2.erase(it); dp2.insert(a); }
    }

    cout << dp << '\n';

    return 0;
}
