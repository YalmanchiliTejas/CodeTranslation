#include <algorithm>
#include <climits>
#include <complex>
#include <cstring>
#include <iostream>
#include <map>
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

// main
int main() {
    const int MAX_H = 100, MAX_W = 100;
    int H, W;
    char a[MAX_H][MAX_W];
    bool row[MAX_H] = {}, col[MAX_W] = {};
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    REP(i, H) {
        if (!row[i]) {
            continue;
        }
        REP(j, W) {
            if (!col[j]) {
                continue;
            }
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
