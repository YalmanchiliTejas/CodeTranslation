#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> a{x};
    vector<int> v(m, -1);
    v[x] = 0;
    ll now = (x*x)%m;
    int l, r;
    {
        int i = 1;
        for ( ; v[now] == -1; ++i) {
            a.emplace_back(now);
            v[now] = i;
            now = (now*now)%m;
        }
        l = v[now], r = i;
    }

    ll val = x, ans = 0;
    for (int i = 0; i < min<ll>(l, x); ++i) {
        ans += val;
        val = (val*val)%m;
    }
    for (int i = l; i < r; ++i) {
        ans += max(0LL, (n-i+r-l-1)/(r-l))*a[i];
    }
    cout << ans << "\n";
    return 0;
}