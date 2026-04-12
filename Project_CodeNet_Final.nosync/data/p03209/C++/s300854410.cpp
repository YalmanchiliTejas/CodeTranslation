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

// AtCoder
// #include <atcoder/all>
// using namespace atcoder;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fls(x) (64 - __builtin_clzll(x))
#define pcnt(x) __builtin_popcountll(x)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

ll maisu_all (ll level) {
    if (level <= 0) return 1;
    return 3 + 2 * maisu_all(level - 1);
}

ll maisu_p (ll level) {
    if (level <= 0) return 1;
    return 1 + 2 * maisu_p(level - 1);
}

ll burger (ll level, ll k) {
    eprintf("level:%lld x:%lld\n", level, k);
    ll m = maisu_all(level - 1);
    if (k == 0) return 0;
    else if (level <= 0) return 1;
    else if (k <= 1) return 0;
    else if (k <= 1 + m) return burger(level - 1, k - 1);
    else if (k <= 2 + 2 * m) return maisu_p(level - 1) + 1 + burger(level - 1, k - m - 2);
    else return maisu_p(level);
}

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x; cin >> n >> x;
    cout << burger(n, x) << "\n";
    // rep (i, 51) eprintf("%lld ", maisu_all(i)); eprintf("\n");
    // rep (i, 51) eprintf("%lld ", maisu_p(i)); eprintf("\n");
    /***************************************************/
    /* Use "submit code (with ACL v1)" when using ACL! */
    /***************************************************/
    return 0;
}