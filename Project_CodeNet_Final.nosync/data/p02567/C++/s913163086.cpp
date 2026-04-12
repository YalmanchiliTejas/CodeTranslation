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
#include <atcoder/all>
using namespace atcoder;

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

int max2 (int a, int b) { return max(a, b); }
int e () { return -1; }
int v;
bool chk (int x) { return x < v; }

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q; cin >> n >> q;
    vector<int> vec(n);
    rep (i, n) cin >> vec[i];
    segtree<int, max2, e> seg(vec);
    rep (_, q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) {
            a--;
            seg.set(a, b);
        } else if (t == 2) {
            a--;
            cout << seg.prod(a, b) << "\n";
        } else if (t == 3) {
            a--; v = b;
            cout << seg.max_right<chk>(a) + 1 << "\n";
        }
    }
    /***************************************************/
    /* Submit this code from the browser if using ACL! */
    /***************************************************/
    return 0;
}
