#include <bits/stdc++.h>
using namespace std;

/*
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using cint = cpp_int;
*/

/*
#pragma GCC optimize("", on)
#pragma GCC optimization_level 3
#define min(...) min({...})
#define max(...) max({...})
#define x first
#define y second
*/

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
const ll MOD = 1e9 + 7;
const ll inf = 1 << 30;
// const ll INF = LONG_MAX;
const ll INF = 1LL << 60;
const ull MAX = ULONG_MAX;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define space ' '
#define def inline auto
#define func inline constexpr ll
#define run __attribute__((constructor)) def _
#define all(v) begin(v), end(v)
#define input(a) scanf("%lld", &(a))
#define print(a) printf("%lld\n", (a))
#define ok(a, b) (0 <= (a) && (a) < (b))
// #define at(pos) pos.x][pos.y
template <class T> using vvector = vector<vector<T>>;
template <class T>
using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;

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
        rep(__i, h) {                                                          \
            rep(__j, w) cerr << a[__i][__j] << space;                          \
            cerr << endl;                                                      \
        }                                                                      \
        cerr << "]" << endl;                                                   \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(__i, n) if (__i) cerr << space << a[__i];                          \
        else cerr << a[__i];                                                   \
        cerr << "]" << endl;                                                   \
    }

struct edge {
    ll to, cost;
    edge(ll a, ll b) : to(a), cost(b) {}
};

struct position {
    ll x, y;
    position() {}
    position(ll a, ll b) : x(a), y(b) {}
    position next(ll k) { return {x + dx[k], y + dy[k]}; }
    ll mdist() { return abs(x) + abs(y); }
    double dist() { return sqrt(x * x + y * y); }
    double norm(ll d) {
        if (d == inf) return max(x, y);
        if (d == 1) return mdist();
        if (d == 2) return dist();
        return 0;
    }
    ll num(ll width) { return abs(x) * width + abs(y); }

    bool operator==(position a) { return x == a.x && y == a.y; }
    bool operator!=(position a) { return x != a.x || y != a.y; }
    bool operator<(position a) { return x < a.x && y < a.y; }
    bool operator>(position a) { return x > a.x && y > a.y; }
    bool operator<=(position a) { return x <= a.x && y <= a.y; }
    bool operator>=(position a) { return x >= a.x && y >= a.y; }
    position operator+(position a) { return position(x + a.x, y + a.y); }
    position operator-(position a) { return position(x - a.x, y - a.y); }
    position operator*(position a) { return position(x * a.x, y * a.y); }
    position operator/(position a) { return position(x / a.x, y / a.y); }
    position operator%(position a) { return position(x % a.x, y % a.y); }
    position complex(position a) {
        return position(x * a.x - y * a.y, x * a.y + y * a.x);
    }
    /*
        // for sort:
        bool operator<(position a) { return x ^ a.x ? x < a.x : y < a.y; }
        bool operator>(position a) { return x ^ a.x ? x > a.x : y > a.y; }
        bool operator<=(position a) { return x ^ a.x ? x < a.x : y <= a.y; }
        bool operator>=(position a) { return x ^ a.x ? x > a.x : y >= a.y; }
    */
};
position Origin = position(0, 0);
using pos = position;
using vec = position;

struct Range {
    ll left, right;
    Range() {}
    Range(ll l, ll r) : left(l), right(r) {}
    ll length() { return right - left; }
    bool operator==(Range A) { return left == A.left && right == A.right; }
    bool operator!=(Range A) { return !(Range(left, right) == A); }
    bool operator>(Range A) { return left < A.left && right > A.right; }
    bool operator<(Range A) { return left > A.left && right < A.right; }
    bool operator>=(Range A) { return left <= A.left && right >= A.right; }
    bool operator<=(Range A) { return left >= A.left && right <= A.right; }
};

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define rep(i, n) for (ll i = 0, _##i = (n); i < _##i; ++i)
#define each(i, a) for (auto &&i : a)
#define loop() for (;;)

// Stream
#define fout(n) cout << fixed << setprecision(n)
#define fasten cin.tie(0), ios::sync_with_stdio(0)

// Speed
run() { fasten, fout(10); }
#pragma GCC optimize("O3")
#pragma GCC target("avx")

// Math
//#define gcd __gcd
func gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
func lcm(ll a, ll b) { return a * b / gcd(a, b); }
func sign(ll a) { return a ? abs(a) / a : 0; }

template <class T> def in() {
    T A;
    cin >> A;
    return A;
}

template <class T>
def out(vector<vector<T>> A, ll H, ll W, char divc = space, char endc = endl) {
    rep(i, H) {
        rep(j, W) {
            if (j)
                cout << divc << A[i][j];
            else
                cout << A[i][j];
        }
        cout << endc;
    }
}

#define fi first
#define se second
ll N, A[3000];
ll DP[3001][3001][2];
ll dp(ll l, ll r, ll n) {
    if (l == r) return n ? -A[l] : A[l];
    if (DP[l][r][n]) return DP[l][r][n];
    ll res, l2 = (l + 1) % N, r2 = (r + N - 1) % N;
    if (n) {
        res = min(dp(l, r2, 0) - A[r], dp(l2, r, 0) - A[l]);
    } else {
        res = max(dp(l, r2, 1) + A[r], dp(l2, r, 1) + A[l]);
    }
    return DP[l][r][n] = res;
}

signed main() {
    cin >> N;
    rep(i, N) cin >> A[i];
    cout << dp(0, N - 1, 0) << endl;
}

// for compilation: g++ -Ofast -march=native -o _ _.cpp -std=c++17
