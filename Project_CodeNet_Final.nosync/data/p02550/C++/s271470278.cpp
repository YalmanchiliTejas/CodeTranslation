
#define INF 10000000000
#define MOD 1000000007

#if 1   // use_templates

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, up) for (ll i = 0; i < (up); ++i)
#define repp(i, up) for (ll i = 0; i <= (up); ++i)
#define rrep(i, lo, up) for (ll i = (lo); i < (up); ++i)
#define rrepp(i, lo, up) for (ll i = (lo); i <= (up); ++i)
#define eep(i, lo, up) for ((i) = (lo); (i) < (up); ++(i))
#define eepp(i, lo, up) for ((i) = (lo); (i) <= (up); ++(i))
#define feach(it, vec) for (auto it = (vec).begin(); it != (vec).end(); ++it)
#define emax(l, r) l = max(l, r)
#define vmin(l, r) l = min(l, r)

template<class T, class U>
bool contains(const T & vec, const U & value) {
    return vec.find(value) != vec.end();
}

ll gcd(ll a, ll b);

ll gcd(ll a, ll b)
{
    if (a < b) {
        return gcd(b, a);
    }
    ll r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

#endif  // end of use_templates


int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    if (x == 0 || m == 1) {
        cout << 0 << endl;
        return 0;
    }
    map<ll, ll> work;
    ll a = x;
    work[a] = 1;
    ll off, loop;
    rrepp(i, 2, m) {
        a = a * a % m;
        auto it = work.find(a);
        if (it != work.end()) {
            off = it->second - 1;
            loop = i - it->second;
            break;
        }
        work[a] = i;
    }
    ll sum = 0;
    ll ii;
    for (a = x, ii = 0; ii < off; a = a * a % m, ++ii) {
        sum += a;
    }
    ll ls = 0;
    for (ii = 0; ii < loop; a = a * a % m, ++ii) {
        ls += a;
    }
    sum += ((n - off) / loop) * ls;
    for (ii = ((n - off) / loop) * loop + off; ii < n; a = a * a % m, ++ii) {
        sum += a;
    }
    cout << sum << endl;
    return 0;
}
