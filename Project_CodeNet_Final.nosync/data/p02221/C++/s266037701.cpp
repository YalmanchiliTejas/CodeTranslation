#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int f (int k, int n) {
    int ret = 0;
    rep (i, n) {
        ret += ((k & (1 << i)) ? (1 << (n - i - 1)) : 0);
    }
    return ret;
}

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<int> > p(n + 1, vector<int>(1 << n));
    rep (i, (1 << n)) cin >> p[0][i];
    rep (i, n) {
        rep (j, (1 << n)) {
            int block = j >> (n - i), fl = (j >> (n - i - 1)) % 2, k = j % (1 << (n - i - 1));
            // eprintf("%d %d %d %d %d\n", i, j, block, fl, k);
            int x = (block << (n - i)) + (2 * k + fl), y = (block << (n - i)) + (2 * k + fl + 1) % (1 << (n - i));
            if (p[i][x] > p[i][y]) swap(x, y);
            p[i + 1][j] = (s[p[i][y] - p[i][x] - 1] == '1' ? p[i][y] : p[i][x]);
            // eprintf("%d %d %d %d %d\n", x, y, p[i][x], p[i][y], p[i + 1][j]);
        }
    }
    rep (i, 1 << n) {
        // eprintf("%d %d %d\n", i, f(i, n), p[n][f(i, n)]);
        cout << p[n][f(i, n)] << "\n";
    }
    return 0;
}
