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
int ceil(int a, int b) {
    return (a + b - 1) / b;
}
int round(int a, int b) {
    return (a + b / 2) / b;
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
template <class T> bool amax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> bool amin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

ll a[51] = {1}, p[51] = {1};

ll f(ll N, ll X) {
    if (N == 0) {
        return X <= 0 ? 0 : 1;
    } else if (X <= 1 + a[N - 1]) {
        return f(N - 1, X - 1);
    } else {
        return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1]);
    }
}

// main
int main() {
    ll N, X;
    cin >> N >> X;
    REP(i, N) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }
    cout << f(N, X) << endl;
    return 0;
}
