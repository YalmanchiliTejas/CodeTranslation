#ifdef DEBUG

#else

#    pragma GCC optimize("O3,no-stack-protector")
#    pragma GCC optimize("unroll-loops")

#    if __cplusplus >= 201703L
#        pragma GCC target("avx2")
#    else
#        pragma GCC target("avx")
#    endif

#endif
// 実数の場合
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Int x, y, z;
    cin >> x >> y >> z;

    Int w = z, ans = 0;
    while (w <= x) {
        ans++;
        w += z + y;
    }
    ans--;

    cout << ans << endl;

    return 0;
}
