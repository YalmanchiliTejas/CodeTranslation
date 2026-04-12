#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <utility>
#include <stack>
#include <numeric>
#include <random>
#include <algorithm>
#include <queue>
#include <functional>
#include <iterator>
#include <list>
#include <unordered_map>
#include <deque>
#include <math.h>
#include <tgmath.h>
using namespace std;

#define rep(i, b, e) for(i = b; i < e; ++i)
#define repr(i, b, e) for (i = b; i >= e; --i)
#define ull unsigned long long int
#define ll long long int
#define pint pair<int, int>

#define M_DEBUG 1
#define PI 3.141592653589793

#define E '\n'

#define print(x) cout << (x) << endl;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << "\n";}
#define INF (1e18)

const ll MAX = 1000000000;
const ll MOD = 1e9 + 7;

ll a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll aabs(ll a) {
    if (a < 0) return -a;
    return a;
}

//fast power
ll calc(ll a, ll b) {
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        ll d = calc(a, b / 2);
        return (d * d) % MOD;
    }
    else return (a * calc(a, b - 1)) % MOD;
}

//fast combination
ll comb(ll n, ll a) {
    ll b = 1, c = 1;
    for (ll i = 1; i <= a; ++i) {
        b = b * i % MOD;
        c = c * (n - i + 1) % MOD;
    }

    return c * calc(b, MOD - 2) % MOD;
}

ll comb2(ll a) {
    ll b = a / 2;
    if (a % 2) {
        b = (a - 1) / 2;
        return (b * a);
    }
    return (b * (a - 1));
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    deque<ll> deq;

    rep (i, 0, n) {
        cin >> a;
        if (i % 2) deq.push_front(a);
        else deq.push_back(a);
    }

    if (n % 2) reverse(deq.begin(), deq.end());

    rep (i, 0, n) cout << deq[i] << ' ';
    cout << endl;

    return 0;
}
