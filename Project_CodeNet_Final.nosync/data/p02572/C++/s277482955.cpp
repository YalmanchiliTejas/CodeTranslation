#ifndef DEBUG
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
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP(i, n) for (int i = 0, i##_len = (n); i <= i##_len; ++i)
#define rep3(i, l, r) for (int i = l, i##_len = (r); i < i##_len; ++i)
#define REP3(i, l, r) for (int i = l, i##_len = (r); i <= i##_len; ++i)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
typedef int64_t Int;
typedef long double Ld;

using namespace std;
using Graph = vector<vector<Int>>;

const Ld pi = M_PI;
const Int MOD = 1000000007;
const Int INF = 1LL << 62;

Int Floor(Int a, Int b) {
    return (a - (a % b)) / b;
}

template <class T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Int n;
    cin >> n;
    vector<Int> a(n), b(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (Int i = 1; i < n; i++) {
        b[i] += b[i - 1];
        b[i] %= MOD;
    }

    Int ans = 0;
    for (Int i = 0; i < n - 1; i++) {
        Int tem = b.back() - b[i];
        if (tem < 0) {
            tem += MOD;
        }

        ans += a[i] * tem;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
