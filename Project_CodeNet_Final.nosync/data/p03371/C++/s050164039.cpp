#include <algorithm>
#include <climits>
#include <complex>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

// using
using namespace std;

// typedef
typedef long long ll;

// define
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQ(c) unique(ALL(c))
#define FOR(i, a, b, c) for (int i = (int)(a); i < (int)(b); i += (int)(c))
#define REP(i, n) FOR(i, 0, n, 1)
#define RFOR(i, a, b, c) for (int i = (int)(a); i >= (int)(b); i -= (int)(c))
#define RREP(i, n) RFOR(i, n, 0, 1)

// functions
template <class T> T ceil(T a, T b) {
    return (a + b - 1) / b;
}
template <class T> T round(T a, T b) {
    return (a + b / 2) / b;
}
template <class T> T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}
template <class T> bool amax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> bool amin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

// main
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    C *= 2;
    int mi = min(X, Y), ma = max(X, Y);
    int res = min(A + B, C) * mi;
    int d1 = A * (X - mi) + B * (Y - mi);
    int d2 = C * (ma - mi);
    cout << res + min(d1, d2) << endl;
    return 0;
}
