#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <utility>
#include <tuple>

#define REP(i, a, b) for (ll i = ll(a); i < ll(b); i++)
using namespace std;
using ll = long long int;
using P = pair<ll, ll>;

// clang-format off
#ifdef _DEBUG_
#define dump(...) do{ cerr << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; PPPPP(__VA_ARGS__); cerr << endl; } while(false)
template<typename T> void PPPPP(T t) { cerr << t; }
template<typename T, typename... S> void PPPPP(T t, S... s) { cerr << t << ", "; PPPPP(s...); }
#else
#define dump(...) do{ } while(false)
#endif
template<typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }
template<typename T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template<typename T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }
template<typename T> void print(T a) { cout << a << endl; }
template<typename T, typename... Ts> void print(T a, Ts... ts) { cout << a << ' '; print(ts...); }
template<typename T> istream &operator,(istream &in, T &t) { return in >> t; }
// clang-format on

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, x, m;
    cin, n, x, m;
    const int sz = 100000;
    vector<ll> a(sz, 0), b(sz, 0);
    REP(i, 0, sz) {
        a[i] = (i * i) % m;
        b[i] = i;
    }
    ll sum = 0;
    while (n) {
        if (n & 1) {
            sum += b[x];
            x = a[x];
        }
        vector<ll> c(sz, 0), d(sz, 0);
        REP(i, 0, sz) {
            c[i] = a[a[i]];
            d[i] = b[i] + b[a[i]];
        }
        a = c;
        b = d;
        n >>= 1;
    }
    print(sum);
    return 0;
}
