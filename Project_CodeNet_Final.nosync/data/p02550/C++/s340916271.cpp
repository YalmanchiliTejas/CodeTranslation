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
template <class T>
using Graph = vector<vector<T>>;

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

template <typename T>
inline T Gcd(T a, T b) {
    T c;
    while (b) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

Int Lcm(Int a, Int b) {
    if (a < b) {
        swap(a, b);
    }

    return a / Gcd(a, b) * b;
}

vector<Int> divisor(Int n) {
    vector<Int> ret;
    for (Int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Int n, x, m;
    cin >> n >> x >> m;

    set<Int> s;
    Int a = x;
    Int ans = 0;
    while (s.count(a) == 0) {
        s.insert(a);
        ans += a;

        a = (a * a) % m;
    }

    Int tem = a;
    Int rocnt = 0;
    Int sum = 0;
    do {
        rocnt++;
        sum += a;

        a = (a * a) % m;
    } while (a != tem);

    if (n < rocnt) {
        ans = 0;
        a = x;
        for (Int i = 0; i < n; i++) {
            ans += a;

            a = (a * a) % m;
        }

    } else {
        Int ro = (n - s.size()) % rocnt;
        for (Int i = 0; i < ro; i++) {
            ans += a;

            a = (a * a) % m;
        }

        ans += sum * ((n - s.size() - ro) / rocnt);
    }

    cout << ans << endl;

    return 0;
}
