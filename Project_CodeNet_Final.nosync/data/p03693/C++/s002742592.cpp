#include <bits/stdc++.h>
using namespace std;

//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// using cint = cpp_int;

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
    rep(i, h) {                                                                \
        rep(j, w) cerr << a[i][j] << space;                                    \
        cerr << endl;                                                          \
    }
#define lldump(a, n) dump(vector<vector<ll>>{a}, 1, n)

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define each(i, a) for (auto &&i : a)
#define rep(i, n) inc(i, 0, n - 1)

// Stream
#define fout(n) cout << fixed << setprecision(n)
#define fasten cin.tie(0), ios::sync_with_stdio(0)

// Speed
run() { fasten, fout(10); }
#pragma GCC optimize("O3")
#pragma GCC optimization_level 3
#pragma GCC target("avx")

// Math
func gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
func lcm(ll a, ll b) { return a * b / gcd(a, b); }

def in() {
    ll A;
    cin >> A;
    return A;
}

ll A, B;
signed main() {
    cin >> A >> A >> B;
    if ((A * 10 + B) % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// for compilation: g++ -Ofast -march=native -o _ _.cpp -std=c++17
