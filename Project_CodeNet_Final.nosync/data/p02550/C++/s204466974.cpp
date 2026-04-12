// Contest: AtCoder Beginner Contest 179 (https://atcoder.jp/contests/abc179)
// Problem: E: Sequence Sum (https://atcoder.jp/contests/abc179/tasks/abc179_e)


// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; int x, m; cin >> n >> x >> m;
    vi next(m);
    rep(i, m)
        next[i] = (ll)i * i % m;

    vi seen(m, -1), path = {x};
    seen[x] = 0;
    while (seen[next[path.back()]] == -1)
        seen[next[path.back()]] = sz(path), path.push_back(next[path.back()]);

    int start = seen[next[path.back()]];
    int cyclen = sz(path) - start;

    ll res = 0;
    rep(i, start)
        res += path[i];

    ll cycsum = 0;
    reps(i, start, sz(path))
        cycsum += path[i];

    ll cyccnt = (n - start) / cyclen;
    res += cycsum * cyccnt;

    rep(i, (n - start) % cyclen)
        res += path[start + i];

    cout << res << '\n';
    return 0;
}
