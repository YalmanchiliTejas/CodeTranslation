// {{{
#include <algorithm>
#include <array>
#include <bitset>
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
    ll n;
    cin >> n;
    map<char, vector<ll>> M;
    rep (i, n) {
        string S;
        cin >> S;
        for (char c = 'a'; c <= 'z'; ++c) {
            M[c].pb(0);
        }
        for (char c : S) {
            M[c][i] += 1;
        }
    }
    vector<pair<char, ll>> V;
    for (auto it : M) {
        ll c = linf;
        for (ll i : it.snd) {
            c = min(c, i);
        }
        V.pb({it.fst, c});
    }
    sort(all(V));
    for (auto v : V) {
        while (v.snd > 0) {
            v.snd -= 1;
            cout << v.fst;
        }
    }
    cout << endl;
}

