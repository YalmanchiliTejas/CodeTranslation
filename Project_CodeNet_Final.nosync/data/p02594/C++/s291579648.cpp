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

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;
typedef long double Ld;

using namespace std;
using Graph = vector<vector<Int>>;

const Ld pi = M_PI;
const Int MOD = 1000000007;
const Int INF = 1LL << 61;

Int Floor(Int a, Int b) {
    return (a - (a % b)) / b;
}

Int Ceil(Int a, Int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return Floor(a, b) + 1;
    }
}

Int digits(Int n) {
    return (Int)to_string(n).size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;

    if (30 <= x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
