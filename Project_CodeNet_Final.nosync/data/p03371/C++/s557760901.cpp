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

using ll [[maybe_unused]] = long long;
using ull [[maybe_unused]] = unsigned long long;
using ld [[maybe_unused]] = long double;

[[maybe_unused]] static constexpr int mod = (int)1e9 + 7;
[[maybe_unused]] static constexpr int inf = 100100100;
[[maybe_unused]] static constexpr ll linf = 1e18;
[[maybe_unused]] static constexpr double eps = 1e-9;
[[maybe_unused]] static constexpr double pi = 3.14159265359;

#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rrep(i, a, b) for (ll i = a; i < b; ++i)
#define rrrep(i, a, b) for (ll i = a; i >= b; --i)
#define all(obj) begin(obj), end(obj)
#define rall(obj) rbegin(obj), rend(obj)
#define pb push_back
#define fst first
#define snd second


int main() {
    // cin.tie(0);
    // ios_base::sync_with_stdio(false);
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    if (A + B > 2 * C) {
        while (X > 0 && Y > 0) {
            ans += 2 * C;
            --X;
            --Y;
        }
    }
    while (X > 0) {
        ans += min(A, 2 * C);
        --X;
    }
    while (Y > 0) {
        ans += min(B, 2 * C);
        --Y;
    }
    cout << ans << endl;
}
