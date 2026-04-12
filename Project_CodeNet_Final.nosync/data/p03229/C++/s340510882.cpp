#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
// using namespace boost::multiprecision;

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// using int128 = __int128;
// using cint = cpp_int;
const ll MOD = 1e9 + 7;
const ll INF = LONG_MAX;
const ull MAX = ULONG_MAX;
#define endl '\n'
#define space ' '
#define def inline auto
#define func inline constexpr ll
#define run __attribute__((constructor)) def _
#define all(v) begin(v), end(v)

// Debug
#define debug(...)                                                             \
    {                                                                          \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                     \
        for (auto &&X : {__VA_ARGS__}) cerr << "[" << X << "] ";               \
        cerr << endl;                                                          \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define each(i, a) for (auto &&i : a)
#define rep(i, n) inc(i, 0, n - 1)

// Stream
#define input(a) scanf("%lld", &(a))
#define output(a) printf("%lld\n", (a))
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

ll N, A[100000], B[100000], S, V;

signed main() {
    cin >> N;
    rep(i, N) cin >> A[i];
    sort(A, A + N);
    ll t = N / 2;
    rep(i, N - N / 2 - ((N & 1) && (N / 2) & 1)) {
        B[t - 1 + (N & 1)] = A[i];
        debug(t);
        if (i & 1)
            t -= (i + 1) * 2;
        else
            t += (i + 1) * 2;
    }
    t = N / 2 + 1;
    rep(i, N / 2 + ((N & 1) && (N / 2) & 1)) {
        B[t - 1 + (N & 1)] = A[N - 1 - i];
        debug(t);
        if (i & 1)
            t += (i + 1) * 2;
        else
            t -= (i + 1) * 2;
    }
    rep(i, N - 1) S += abs(B[i + 1] - B[i]);
    rep(i, N) debug(B[i]);

    t = N / 2;
    rep(i, N - N / 2 - ((N & 1) && (N / 2) & 1)) {
        B[t - 1 + (N & 1)] = A[N - 1 - i];
        debug(t);
        if (i & 1)
            t -= (i + 1) * 2;
        else
            t += (i + 1) * 2;
    }
    t = N / 2 + 1;
    rep(i, N / 2 + ((N & 1) && (N / 2) & 1)) {
        B[t - 1 + (N & 1)] = A[i];
        debug(t);
        if (i & 1)
            t += (i + 1) * 2;
        else
            t -= (i + 1) * 2;
    }
    rep(i, N - 1) V += abs(B[i + 1] - B[i]);
    rep(i, N) debug(B[i]);

    cout << max(S, V) << endl;
}

// for compilation: g++ -Ofast -march=native -o _ _.cpp -std=c++17
