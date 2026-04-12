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


ll N, M;
map<ll, vector<ll>> G;

void solve(ll n, set<ll>& s, ll& ans) {
    if (s.size() == N) {
        ++ans;
        return;
    }
    for (auto i : G[n]) {
        if (s.count(i)) continue;
        s.ist(i);
        solve(i, s, ans);
        s.erase(i);
    }
}


int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep (i, M) {
        ll a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    ll ans = 0;
    set<ll> s = {1};
    solve(1, s, ans);
    cout << ans << endl;
}
