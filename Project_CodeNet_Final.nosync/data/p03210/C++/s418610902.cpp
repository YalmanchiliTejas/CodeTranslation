#include <bits/stdc++.h>
using namespace std;

//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using cint = cpp_int;
//#pragma GCC optimize("", on)
//#pragma GCC optimization_level 3
//#define min(...) min({...})
//#define max(...) max({...})

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = LONG_MAX;
const ull MAX = ULONG_MAX;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define endl '\n'
#define space ' '
#define def inline auto
#define func inline constexpr ll
#define run __attribute__((constructor)) def _
#define all(v) begin(v), end(v)
#define input(a) scanf("%lld", &(a))
#define print(a) printf("%lld\n", (a))

// Debug
#define debug(...)                                                             \
    {                                                                          \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                     \
        for (auto &&X : {__VA_ARGS__}) cerr << "[" << X << "] ";               \
        cerr << endl;                                                          \
    }

#define dump(a, h, w)                                                          \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [" << endl;                      \
        rep(i, h) {                                                            \
            rep(j, w) cerr << a[i][j] << space;                                \
            cerr << endl;                                                      \
        }                                                                      \
        cerr << "]" << endl;                                                   \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(i, n) if (i) cerr << space << a[i];                                \
        else cerr << a[i];                                                     \
        cerr << "]" << endl;                                                   \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define each(i, a) for (auto &&i : a)
#define rep(i, n) inc(i, 0, n - 1)
#define loop() for (;;)

// Stream
#define fout(n) cout << fixed << setprecision(n)
#define fasten cin.tie(0), ios::sync_with_stdio(0)

// Speed
run() { fasten, fout(10); }
#pragma GCC optimize("O3")
#pragma GCC target("avx")

// Math
func gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
func lcm(ll a, ll b) { return a * b / gcd(a, b); }
func sign(ll a) { return a ? abs(a) / a : 0; }

def in() {
    ll A;
    cin >> A;
    return A;
}

signed main() {
    ll N;
    cin >> N;
    cout << ((N - 3) * (N - 5) * (N - 7) ? "NO" : "YES") << endl;
}

// for compilation: g++ -Ofast -march=native -o _ _.cpp -std=c++17
