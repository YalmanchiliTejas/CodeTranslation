// Contest: AtCoder Beginner Contest 154 (https://atcoder.jp/contests/abc154)
// Problem: E: Almost Everywhere Zero (https://atcoder.jp/contests/abc154/tasks/abc154_e)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
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

#if __cpp_lib_nonmember_container_access >= 201411
#   define sz(x) ((int)size(x))
#else
#   define sz(x) ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define all(a)         (a).begin(),(a).end()
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

#if __has_cpp_attribute(maybe_unused) >= 201603
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n; int ik; cin >> n >> ik;
    ll d = sz(n);

    string num(d, '0');
    ll res = 0;
    rep(i, d) reps(iv, 1, 10) {
        if (ik == 1) {
            num[i] = '0' + iv;
            res += num <= n;
            num[i] = '0';
            continue;
        }
        num[i] = ('0' + iv + 1);
        if (num <= n) {
            num[i] = '0';
            if (ik == 2)
                res += (d-i-1)*9;
            else
                res += (d-i-1)*(d-i-2)/2*9*9;
            continue;
        }
        num[i] = '0' + iv;
        reps(j, i+1, d) reps(jv, 1, 10) {
            if (ik == 2) {
                num[j] = '0' + jv;
                res += num <= n;
                num[j] = '0';
                continue;
            }
            num[j] = '0' + jv + 1;
            if (num <= n) {
                num[j] = '0';
                if (ik == 2)
                    ++res;
                else
                    res += (d-j-1) * 9;
                continue;
            }
            num[j] = '0' + jv;
            reps(k, j+1, d) reps(kv, 1, 10) {
                num[k] = '0' + kv;
                res += num <= n;
                num[k] = '0';
            }
            num[j] = '0';
        }
        num[i] = '0';
    }

    cout << res << '\n';
    return 0;
}