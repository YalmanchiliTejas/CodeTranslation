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
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n); rep (i, n) cin >> a[i];
    if (n % 2 == 0) {
        vector<ll> l(n / 2 + 1), r(n / 2 + 1);
        for (int i = 0; i * 2 < n; i++) {
            l[i + 1] = l[i] + a[2 * i];
        }
        for (int i = n / 2 - 1; i >= 0; i--) {
            r[i] = r[i + 1] + a[2 * i + 1];
        }
        rep (i, l.size()) eprintf("%lld ", l[i]); eprintf("\n");
        rep (i, r.size()) eprintf("%lld ", r[i]); eprintf("\n");
        ll ans = -(ll)1e18;
        rep (i, n / 2 + 1) chmax(ans, l[i] + r[i]);
        cout << ans << "\n";
    } else {
        vector<ll> l(n / 2 + 2), m(n / 2 + 1), r(n / 2 + 2);
        rep (i, n / 2 + 1) l[i + 1] = l[i] + a[2 * i];
        for (int i = n / 2; i >= 0; i--) r[i] = r[i + 1] + a[2 * i];
        for (int i = n / 2 - 1; i >= 0; i--) m[i] = m[i + 1] + a[2 * i + 1];
        rep (i, l.size()) eprintf("%4lld ", l[i]); eprintf("\n");
        rep (i, r.size()) eprintf("%4lld ", r[i]); eprintf("\n");
        rep (i, m.size()) eprintf("%4lld ", m[i]); eprintf("\n");

        vector<ll> mr(n / 2 + 1); mr[n / 2] = 0;
        reprev (i, n / 2) mr[i] = max(mr[i + 1] + a[1 + i * 2], r[i + 1]);
        rep (i, mr.size()) eprintf("%4lld ", mr[i]); eprintf("\n");
        ll ans = l[n / 2];
        rep (i, n / 2 + 1) chmax(ans, l[i] + mr[i]);
        cout << ans << "\n";
    }
    return 0;
}