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

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x, m; cin >> n >> x >> m;
    vector<ll> rem(2 * m + 10);
    ll start = 0, shuki = 0;
    map<ll, ll> mp;
    rem[0] = x;
    mp[x] = 1;
    rep (i, 1, 2 * m + 1) {
        rem[i] = ((rem[i - 1] % m) * (rem[i - 1] % m)) % m;
        if (int k = mp[rem[i]]; k != 0) {
            start = i + 1;
            shuki = i + 1 - k;
            break;
        }
        mp[rem[i]] = i + 1;
    }
    // rep (i, start) eprintf("%lld%c", rem[i], " \n"[i + 1 == start]);
    eprintf("%lld, %lld\n", start, shuki);
    if (n <= start) {
        ll ans = 0;
        rep (i, n) ans += rem[i];
        cout << ans << "\n";
    } else {
        ll ans = 0;
        rep (i, start) ans += rem[i];
        ll k = (n - start) / shuki, r = (n - start) % shuki;
        rep (i, shuki) ans += k * rem[start - shuki + i - 1];
        rep (i, start - shuki, start - shuki + r) ans += rem[i];
        cout << ans << "\n";
    }

    /***************************************************/
    /* Submit this code from the browser if using ACL! */
    /***************************************************/
    return 0;
}