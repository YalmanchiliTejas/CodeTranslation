#include <iostream>
#include <fstream>
#include <iomanip>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>
#include <random>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define sz(a) static_cast<int>((a).size())
#define endl '\n'

using ll = long long;

const ll INF = static_cast<ll>(1e9) + 7;
const int MAXN = static_cast<int>(2e5) + 17;

int n;
int h[MAXN];

bool read() {
    if (!(cin >> n))
        return false;

    forn (i, n)
        cin >> h[i];

    return true;
}

ll binpow(ll x, ll n) {
    ll res = 1ll;

    for (; n > 0; n >>= 1, x = x * x % INF)
        if (n & 1)
            res = res * x % INF;

    return res;
}

pair<ll, ll> dfs(int lx, int rx, int ly, int ry) {
    if (rx == lx)
        return make_pair(binpow(2ll, ry - ly + 1), 0);

    if (*max_element(h + lx, h + rx + 1) == ry) {
        return make_pair(binpow(2ll, ry - ly + 1), (INF + binpow(2ll, rx - lx + 1) - 2) % INF);
    }

    pair<ll, ll> res = {1, 1};

    for (int i = lx; i <= rx; ++i)
        if (h[i] > ry) {
            int l = i, r = i, hh = h[i];

            for (; r <= rx && h[r] > ry; ++r)
                hh = min(hh, h[r]);

            --r;
            auto p = dfs(l, r, ry + 1, hh);
            res.first *= p.first;
            res.first %= INF;
            res.second *= (2ll * p.first + p.second);
            res.second %= INF;
            i = r;
        } else {
            res.second += res.second;

            if (res.second >= INF)
                res.second -= INF;
        }

    res.second -= 2ll * res.first % INF;

    if (res.second < 0)
        res.second += INF;

    res.first *= binpow(2ll, ry - ly + 1);
    res.first %= INF;

    return res;
}

void solve() {
    auto p = dfs(0, n - 1, 1, *min_element(h, h + n));
    ll ans = (p.first + p.second) % INF;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::mt19937 rand('S' + 'E' + 'R' + 'E' + 'Z' + 'H' + 'K' + 'A');

#ifdef SEREZHKA
    freopen("file.in", "r", stdin);
#endif

    while (read())
        solve();

    return 0;
}

