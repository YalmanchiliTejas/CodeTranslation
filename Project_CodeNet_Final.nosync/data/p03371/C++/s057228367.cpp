#include <iostream>
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

// constexpr inline ll MOD = 1'000'000'007;

int main()
{
    // 入出力
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c;
    int x,y,z;
    cin>>a>>b>>c>>x>>y;
    z=max(x,y);
    int res = 2001'000'000;
    rep(i, z+1){
        int num_a = max(0, x - i);
        int num_b = max(0, y - i);
        res = min(res, num_a * a + num_b * b + 2 * i * c);
    }
    cout<<res<<endl;

    return 0;
}
