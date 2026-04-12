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

ull a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

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

int main(void) {
    string ss;
    cin >> ss;
    
    if (ss[0] == ss[1] && ss[1] == ss[2] && ss[0] == ss[2]) {
        cout << "No" << endl;

    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

