#ifdef DEBUG

#else

#    pragma GCC optimize("O3,no-stack-protector")
#    pragma GCC optimize("unroll-loops")

#    if __cplusplus < 201703L
#        pragma GCC target("avx")
#    else
#        pragma GCC target("avx2")
#    endif

#endif
// 実数の場合
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;
typedef long double Ld;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

vector<Int> len, bread, patty;

Int f(Int n, Int x) {
    if (n == 0) {
        if (x <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (x <= 1 + len[n - 1]) {
        return f(n - 1, x - 1);
    } else {
        return patty[n - 1] + 1 + f(n - 1, x - 2 - len[n - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Int n, x;
    cin >> n >> x;

    int c = 51;
    len = bread = patty = vector<Int>(c + 1);
    len[0] = 1;
    bread[0] = 0;
    patty[0] = 1;
    for (int i = 1; i <= c; i++) {
        bread[i] = bread[i - 1] * 2 + 2;
        patty[i] = patty[i - 1] * 2 + 1;
        len[i] = bread[i] + patty[i];
    }

    cout << f(n, x) << endl;

    return 0;
}