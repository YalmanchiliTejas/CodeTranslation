#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <numeric>
#include <string>
#include <bitset>
#include <functional>

using ld = long double;
using vld = std::vector<ld>;
using vvld = std::vector<vld>;
using vvvld = std::vector<vvld>;
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using pll = std::pair<ll, ll>;
using vpll = std::vector<pll>;
using str = std::string;
using vstr = std::vector<str>;

template<typename T> bool chmin(T a, T &b) {
    return a < b ? b = a, true : false;
}
template<typename T> bool chmax(T a, T &b) {
    return a > b ? b = a, true : false;
}

constexpr ld PI = 3.141592653589793L;
constexpr ld EPS = std::numeric_limits<ld>::epsilon();

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }
bool isprime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
vll sieve(ll n) {
    str flg(n + 1, '1');
    for (ll i = 2; i * i <= n; i++) {
        if (flg[i] == '0') continue;
        for (ll j = i * i; j <= n; j += i)
            flg[j] = '0';
    }
    vll res;
    for (ll i = 2; i <= n; i++)
        if (flg[i] == '1') res.push_back(i);
    return res;
}
ll rpow(ll x, ll n) {
    if (n == 0) return 1;
    ll k = 1;
    for (; n > 1; n /= 2) {
        if (n & 1) k *= x;
        x *= x;
    }
    return k * x;
}
ll modpow(ll x, ll n, ll mod) {
    if (n == 0) return 1;
    ll k = 1;
    for (; n > 1; n /= 2) {
        if (n & 1) (k *= x) %= mod;
        (x *= x) %= mod;
    }
    return k * x % mod;
}
ll modcomb(ll n, ll r, ll mod) {
    if (r < 0 || n < r) return 0;
    chmin(n - r, r);
    ll mul = 1, div = 1;
    for (ll i = 0; i < r; i++) {
        (mul *= n - i) %= mod;
        (div *= i + 1) %= mod;
    }
    return mul * modpow(div, mod - 2, mod) % mod;
}

/*----------------------------------------------------------------*/

void solve();

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::setprecision(15);

    solve();
}
void solve() {
    ll n, m;
    std::cin >> n >> m;

    vvll g(n);
    for (ll i = 0; i < m; i++) {
        ll a, b; std::cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vll p(n);
    std::iota(p.begin(), p.end(), 0);

    ll ans = 0;
    do {
        bool flg = true;
        for (ll i = 0; i < n - 1; i++) {
            auto j = std::find(g[p[i]].begin(), g[p[i]].end(), p[i + 1]);
            if (j == g[p[i]].end()) { flg = false; break; }
        }
        ans += flg;
    } while (std::next_permutation(p.begin(), p.end()) && !p[0]);

    std::cout << ans << '\n';
}
