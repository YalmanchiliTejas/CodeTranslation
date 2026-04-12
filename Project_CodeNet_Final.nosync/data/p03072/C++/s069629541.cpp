// {{{
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// }}}

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr int mod = (int)1e9 + 7;
static constexpr int inf = 100100100;
static constexpr ll linf = 1e18;
static constexpr double eps = 1e-9;
static constexpr double pi = 3.14159265359;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rrep(i, n) for (ll i = n; i >= 0; --i)
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define pb push_back
#define ist insert
#define fst first
#define snd second



int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> H;
    rep (i, N) {
        ll h;
        cin >> h;
        H.pb(h);
    }
    ll ans = 0;
    rep (i, N) {
        bool f = true;
        for (ll j = 0; j <= i; ++j) {
            f = f && (H[i] >= H[j]);
        }
        if (f) ++ans;
    }
    cout << ans << endl;
}
