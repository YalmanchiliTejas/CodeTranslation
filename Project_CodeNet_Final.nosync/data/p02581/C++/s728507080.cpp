#ifndef AUTO_UTIL_HEADER_HPP
#define AUTO_UTIL_HEADER_HPP

#include <bits/stdc++.h>
#include <cassert>

using std::cin, std::cout, std::bitset, std::complex;
using std::vector, std::array, std::string, std::pair, std::list, std::queue, std::deque;
using std::priority_queue, std::set, std::map, std::unordered_map;
using std::sort, std::greater, std::min, std::max, std::reverse;
using std::min_element, std::max_element, std::accumulate;

using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using ull = unsigned long long int;
using ll = long long int;
using vll = vector<ll>; using vvll = vector<vll>; using vvvll = vector<vvll>;
using vd = vector<double>; using vvd = vector<vd>; using vvvd = vector<vvd>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using cdouble = complex<double>;

const double eps = 1e-7;
#define Loop(i, n) for(int i = 0; i < int(n); i++)
#define Loopll(i, n) for(ll i = 0; i < ll(n); i++)
#define Loop1(i, n) for(int i = 1; i <= int(n); i++)
#define Loopll1(i, n) for(ll i = 1; i <= ll(n); i++)
#define Loopr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define Looprll(i, n) for(ll i = ll(n) - 1; i >= 0; i--)
#define Loopr1(i, n) for(int i = int(n); i >= 1; i--)
#define Looprll1(i, n) for(ll i = ll(n); i >= 1; i--)
#define Foreach(buf, container) for(const auto &buf : container)
#define Foreachr(buf, container)  for(const auto &buf : reversed(container))
#define Loopdiag(i, j, h, w, sum) for(int i = ((sum) >= (h) ? (h) - 1 : (sum)), j = (sum) - i; i >= 0 && j < (w); i--, j++)
#define Loopdiagr(i, j, h, w, sum) for(int j = ((sum) >= (w) ? (w) - 1 : (sum)), i = (sum) - j; j >= 0 && i < (h); j--, i++)
#define Loopdiagsym(i, j, h, w, gap) for (int i = ((gap) >= 0 ? (gap) : 0), j = i - (gap); i < (h) && j < (w); i++, j++)
#define Loopdiagsymr(i, j, h, w, gap) for (int i = ((gap) > (h) - (w) - 1 ? (h) - 1 : (w) - 1 + (gap)), j = i - (gap); i >= 0 && j >= 0; i--, j--)
#define Loopitr(itr, container) for(auto itr = container.begin(); itr != container.end(); itr++)
#define quickio() std::ios::sync_with_stdio(false); std::cin.tie(0);
#define bitmanip(m,val) static_cast<bitset<(int)m>>(val)
#define Comp(type_t) bool operator<(const type_t &another) const
#define fst first
#define snd second
bool feq(double x, double y) { return abs(x - y) <= eps; }
bool inrange(ll x, ll t) { return x >= 0 && x < t; }
bool inrange(vll xs, ll t) { Foreach(x, xs) if (!(x >= 0 && x < t)) return false; return true; }
int ceillog2(ll x) { int m = int(log2(x)); return m + ((1LL << m) < x ? 1 : 0); }
int floorlog2(ll x) { int m = int(log2(x)); return m - ((1LL << m) > x ? 1 : 0); }
const string endl = "\n";
template<class T> T reversed(T container) { reverse(container.begin(), container.end()); return container; }
template<class T> void printv(const vector<T> &v) { for (const T &x : v) cout << x << " "; cout << endl; }
template<class T> void printmx(const vector<vector<T>> &mx) { for (const vector<T> &v : mx) printv(v); }
ll rndf(double x) { return (ll)(x + (x >= 0 ? 0.5 : -0.5)); }
ll floorsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (m*  m <= x ? 0 : -1); }
ll ceilsqrt(ll x) { ll m = (ll)sqrt((double)x); return m + (x <= m * m ? 0 : 1); }
ll rnddiv(ll a, ll b) { return (a / b + (a % b * 2 >= b ? 1 : 0)); }
ll ceildiv(ll a, ll b) { return (a / b + (a % b == 0 ? 0 : 1)); }
ll gcd(ll m, ll n) { if (n == 0) return m; else return gcd(n, m % n); }
ll lcm(ll m, ll n) { return ll(m) * ll(n) / gcd(m, n); }

#endif // AUTO_UTIL_HEADER_HPP

//========================================================================//

struct entry_t {
    int x, y, val;
};

vvi dp;
vector<entry_t> entries;
vi max_xwise;
vi max_ywise;
int max_all;

void upd(int &u, const int v) {
    u = max(u, v);
}

void entry_upd(int x, int y, int val) {
    entries.push_back({x, y, val});
}

void do_upd() {
    for (const auto &entry : entries) {
        upd(dp[entry.x][entry.y], entry.val);
        upd(max_xwise[entry.x], entry.val);
        upd(max_ywise[entry.y], entry.val);
        upd(max_all, entry.val);
    }
    entries.clear();
}

int main() {
    int n; cin >> n;
    vi a(n * 3);
    Loop(i, n * 3) {
        cin >> a[i];
        a[i]--;
    }
    dp = vvi(n, vi(n, INT_MIN));
    entries = {};
    max_xwise = vi(n, INT_MIN);
    max_ywise = vi(n, INT_MIN);
    max_all = INT_MIN;
    int acc = 0;
    //
    entry_upd(a[0], a[1], 0);
    entry_upd(a[1], a[0], 0);
    do_upd();
    //
    for (int i = 0; i < n - 1; ++i) {
        vi z = { a[i * 3 + 2], a[i * 3 + 3], a[i * 3 + 4] };
        std::sort(z.begin(), z.end()); 
        int z0 = z[0];
        int z1 = z[1];
        int z2 = z[2];
        //
        if (z0 == z1 && z1 == z2) {
            acc++;
        }
        else {
            if (z0 == z1) std::swap(z0, z2);
            if (z1 == z2) {
                Loop(x, n) {
                    entry_upd(x, z0, dp[x][z1] + 1);
                }
                Loop(y, n) {
                    entry_upd(z0, y, dp[z1][y] + 1);
                }
                entry_upd(z1, z1, dp[z0][z0] + 1);
                entry_upd(z1, z1, max_all);
                entry_upd(z0, z1, max_all);
                entry_upd(z1, z0, max_all);
                Loop(x, n) {
                    entry_upd(x, z0, max_xwise[x]);
                }
                Loop(y, n) {
                    entry_upd(z0, y, max_ywise[y]);
                }
            }
            else {
                entry_upd(z1, z2, dp[z0][z0] + 1);
                entry_upd(z2, z1, dp[z0][z0] + 1);
                entry_upd(z2, z0, dp[z1][z1] + 1);
                entry_upd(z0, z2, dp[z1][z1] + 1);
                entry_upd(z0, z1, dp[z2][z2] + 1);
                entry_upd(z1, z0, dp[z2][z2] + 1);
                //
                entry_upd(z1, z2, max_all);
                entry_upd(z2, z1, max_all);
                entry_upd(z2, z0, max_all);
                entry_upd(z0, z2, max_all);
                entry_upd(z0, z1, max_all);
                entry_upd(z1, z0, max_all);
                //
                Loop(x, n) {
                    entry_upd(x, z0, max_xwise[x]);
                    entry_upd(x, z1, max_xwise[x]);
                    entry_upd(x, z2, max_xwise[x]);
                }
                Loop(y, n) {
                    entry_upd(z0, y, max_ywise[y]);
                    entry_upd(z1, y, max_ywise[y]);
                    entry_upd(z2, y, max_ywise[y]);
                }
            }
            do_upd();
        }
    }
    //
    int z0 = a[n * 3 - 1];
    entry_upd(z0, z0, dp[z0][z0] + 1);
    do_upd();
    cout << acc + max_all << endl;
}
