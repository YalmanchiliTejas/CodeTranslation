#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

ll pw(ll x, ll y, ll mod) {
    if (y == 0) return 1;
    else if (y == 1) return x % mod;
    else if (y % 2 == 0) {
        ll p = pw(x, y / 2, mod);
        return p * p % mod;
    }
    else {
        ll p = pw(x, y / 2, mod);
        return p * p % mod * x % mod;
    }
}

ll dv(ll x, ll y, ll mod) {
    return x * pw(y, mod - 2, mod) % mod;
}
 
ll comb(ll cn, ll cr, ll mod) {
    ll v = 1;
    if (cn < cr || cn < 0 || cr < 0) return 0;
    for (int i = 1; i <= cr; i++) {
        v = v * (cn - i + 1) % mod;
        v = v * dv(1, i, mod) % mod;
    }
    return v;
}

int main() {
    ll n, m, k, mod = 1e9 + 7;
    cin >> n >> m >> k;

    ll s, t, ss, tt;
    s = pw(m, 2, mod) * comb(n * m - 2, k - 2, mod) % mod;
    ss = (n * (n - 1) / 2 % mod * n % mod) % mod;
    ss -= n * (n - 1) % mod * dv(2 * n - 1, 6, mod) % mod;
    s = s * ss % mod;
    t = pw(n, 2, mod) * comb(n * m - 2, k - 2, mod) % mod;
    tt = (m * (m - 1) / 2 % mod * m % mod) % mod;
    tt -= m * (m - 1) % mod * dv(2 * m - 1, 6, mod) % mod;
    t = t * tt % mod;
    cout << (s + t) % mod << endl;
}
