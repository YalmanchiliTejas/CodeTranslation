#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <bitset>

using namespace std;

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
template <typename T> void print_container(ostream& os, const T& c) { const char* _s = " "; if (!c.empty()) { __typeof__(c.begin()) last = --c.end(); foreach (it, c) { os << *it; if (it != last) os << _s; } } }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const deque<T>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }

template <typename T> void print(T a, int n, const string& split = " ") { for (int i = 0; i < n; i++) { cout << a[i]; if (i + 1 != n) cout << split; } cout << endl; }
template <typename T> void print2d(T a, int w, int h, int width = -1, int br = 0) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) { if (width != -1) cout.width(width); cout << a[i][j] << ' '; } cout << endl; } while (br--) cout << endl; }
template <typename T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
#define dump(v) (cout << #v << ": " << v << endl)

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define erep(i, n) for (int i = 0; i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)
#define ten(n) ((long long)(1e##n))

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;
typedef pair<int, int> pint;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

class ModUtil
{
private:
    ll max, mod;
    vector<ll> _inv, _fact, _inv_fact;

    void init()
    {
        _inv[1] = 1;
        for (int i = 2; i <= max; ++i)
            _inv[i] = _inv[mod % i] * (mod - mod / i) % mod;

        _fact[0] = 1;
        for (int i = 1; i <= max; ++i)
            _fact[i] = i * _fact[i - 1] % mod;

        _inv_fact[0] = 1;
        for (int i = 1; i <= max; ++i)
            _inv_fact[i] = _inv[i] * _inv_fact[i - 1] % mod;
    }

public:
    ModUtil(ll max, ll mod)
        : max(max), mod(mod), _inv(max + 1), _fact(max + 1), _inv_fact(max + 1)
    {
        init();
    }


    ll inv(ll n) const { return _inv[n]; }
    ll fact(ll n) const { return _fact[n]; }
    ll inv_fact(ll n) const { return _inv_fact[n]; }
    ll P(ll n, ll k) const { return _fact[n] * _inv_fact[n - k] % mod; }
    ll C(ll n, ll k) const { return P(n, k) * _inv_fact[k] % mod; }
};

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    const ll mod = ten(9) + 7;
    ModUtil mod_util(n + 1, mod);

    static ll dp[1024][1024];
    dp[a][n] = 1;
    for (int size = a; size <= b; ++size) {
        for (int remain = 0; remain <= n; ++remain) {
            (dp[size + 1][remain] += dp[size][remain]) %= mod;

            ll nume = 1;
            int rem = remain;
            for (int freq = 1; freq <= d && rem >= size; ++freq) {
                (nume *= mod_util.C(rem, size)) %= mod;
                rem -= size;

                if (freq >= c) {
                    ll ways = nume * mod_util.inv_fact(freq) % mod;
                    (dp[size + 1][rem] += ways * dp[size][remain]) %= mod;
                }
            }
        }
    }
    cout << dp[b + 1][0] << endl;
}
