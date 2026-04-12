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
    int N;
    cin >> N;
    cout << N * 800 - N / 15 * 200 << endl;
    return 0;
}
