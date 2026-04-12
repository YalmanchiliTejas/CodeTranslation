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


vector<ll> A, B;

auto lis() {
    vector<ll> LIS;
    rep (i, A.size()) {
        if (LIS.size() == 0 || A[i] >= LIS[LIS.size() - 1]) {
            LIS.pb(A[i]);
        } else {
            auto it = upper_bound(all(LIS), A[i]);
            if (it != LIS.end()) {
                *it = A[i];
            }
        }
    }
    return LIS;
}

int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    rep (i, N) {
        ll a;
        cin >> a;
        B.pb(a);
    }
    rep (i, N) {
        A.pb(B[N - i - 1]);
    }
    cout << lis().size() << endl;
}
