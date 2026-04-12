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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> fi(H);
    for (int i = 0; i < H; i++) {
        cin >> fi[i];
    }

    bool ans = true;
    for (int h = 0; h < H && ans; h++) {
        for (int w = 0; w < W && ans; w++) {
            if (fi[h][w] == '.') {
                continue;
            }

            if (w + 1 < W && h + 1 < H) {
                if (fi[h][w + 1] == '#' && fi[h + 1][w] == '#') {
                    ans = false;
                    break;
                }
            }

            if (0 <= w - 1 && 0 <= h - 1) {
                if (fi[h][w - 1] == '#' && fi[h - 1][w] == '#') {
                    ans = false;
                    break;
                }
            }
        }
    }

    if (ans) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
