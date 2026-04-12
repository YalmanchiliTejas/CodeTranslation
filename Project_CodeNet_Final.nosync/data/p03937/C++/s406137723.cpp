#include <bits/stdc++.h>
using namespace std;

// Define
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T> using pvector = vector<pair<T, T>>;
template <class T>
using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
constexpr const ll dx[4] = {1, 0, -1, 0};
constexpr const ll dy[4] = {0, 1, 0, -1};
constexpr const ll MOD = 1e9 + 7;
constexpr const ll mod = 998244353;
constexpr const ll INF = 1LL << 60;
constexpr const ll inf = 1 << 30;
constexpr const char rt = '\n';
constexpr const char sp = ' ';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define elif else if
#define all(a, v, ...)                                                         \
    ([&](decltype((v)) w) { return (a)(begin(w), end(w), ##__VA_ARGS__); })(v)
#define rall(a, v, ...)                                                        \
    ([&](decltype((v)) w) { return (a)(rbegin(w), rend(w), ##__VA_ARGS__); })(v)
#define fi first
#define se second

template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

// Debug
#define debug(...)                                                             \
    {                                                                          \
        cerr << __LINE__ << ": " << #__VA_ARGS__ << " = ";                     \
        for (auto &&X : {__VA_ARGS__}) cerr << "[" << X << "] ";               \
        cerr << rt;                                                            \
    }

#define dump(a, h, w)                                                          \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [" << rt;                        \
        rep(_i, h) {                                                           \
            rep(_j, w) cerr << a[_i][_j] << sp;                                \
            cerr << rt;                                                        \
        }                                                                      \
        cerr << "]" << rt;                                                     \
    }

#define vdump(a, n)                                                            \
    {                                                                          \
        cerr << __LINE__ << ": " << #a << " = [";                              \
        rep(_i, n) if (_i) cerr << sp << a[_i];                                \
        else cerr << a[_i];                                                    \
        cerr << "]" << rt;                                                     \
    }

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i <= _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i >= _##i; --i)
#define rep(i, n) for (ll i = 0, _##i = (n); i < _##i; ++i)
#define each(i, a) for (auto &&i : a)

// Stream
#define fout(n) cout << fixed << setprecision(n)
struct io {
    io() { cin.tie(nullptr), ios::sync_with_stdio(false); }
} io;

// Speed
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

// Math
inline constexpr ll gcd(const ll a, const ll b) {
    return b ? gcd(b, a % b) : a;
}
inline constexpr ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

inline constexpr ll modulo(const ll n, const ll m = MOD) {
    ll k = n % m;
    return k + m * (k < 0);
}
inline constexpr ll chmod(ll &n, const ll m = MOD) {
    n %= m;
    return n += m * (n < 0);
}
inline constexpr ll mpow(ll a, ll n, const ll m = MOD) {
    ll r = 1;
    rep(i, 64) {
        if (n & (1LL << i)) r *= a;
        chmod(r, m);
        a *= a;
        chmod(a, m);
    }
    return r;
}
inline ll inv(const ll n, const ll m = MOD) {
    ll a = n, b = m, x = 1, y = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        x -= t * y;
        swap(x, y);
    }
    return modulo(x, m);
}

template <typename T = ll> struct Dijkstra {
    ll V;
    using P = pair<ll, T>;
    using P2 = pair<T, ll>;
    vector<vector<P>> G;
    vector<T> dist;
    vector<bool> used;
    Dijkstra(ll v) : V(v), G(v), dist(v), used(v) {}
    void setDist(ll a, ll b, T d) { G[a].push_back(P(b, d)); }
    void calc(ll s = 0) {
        priority_queue<P2, vector<P2>, greater<P2>> Q;
        Q.push(P2(0, s));
        fill_n(dist.begin(), V, INF);
        fill_n(used.begin(), V, false);
        while (!Q.empty()) {
            T d;
            ll t;
            tie(d, t) = Q.top(), Q.pop();
            if (used[t]) continue;
            used[t] = true, dist[t] = d;
            for (P e : G[t]) {
                if (dist[e.first] <= d + e.second) continue;
                Q.push(P2(d + e.second, e.first));
            }
        }
    }
};

signed main() {
    ll H, W;
    cin >> H >> W;
    string S[H];
    rep(i, H) cin >> S[i];
    Dijkstra<> d(H * W);
    ll cnt = 0;
    rep(i, H) rep(j, W) rep(k, 2) {
        ll x = i + dx[k], y = j + dy[k];
        if (S[i][j] == '#') cnt++;
        if (0 <= x and x < H and 0 <= y and y < W and S[i][j] == '#' and
            S[x][y] == '#')
            d.setDist(i * W + j, x * W + y, 1);
    }
    d.calc();
    cout << (d.dist[H * W - 1] != INF and cnt / 2 == H + W - 1 ? "Possible"
                                                               : "Impossible")
         << rt;
}

// -g -D_GLIBCXX_DEBUG -fsanitize=undefined
