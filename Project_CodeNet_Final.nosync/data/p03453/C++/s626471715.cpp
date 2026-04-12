#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORR(i, a, b) for(int i = (a); i > (b); --i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt(x) __builtin_popcount(x)
#define lbit(x) __builtin_ffsll(x)
#define rbit(x) __builtin_clzll(x)
#define SZ(x) ((long long)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
#define cinfast() cin.tie(0), ios::sync_with_stdio(false)
#define PERM(c)                                                                \
    sort(All(c));                                                              \
    for(bool cp = true; cp; cp = next_permutation(All(c)))
#define MKORDER(n)                                                             \
    vector<int> od(n);                                                         \
    iota(All(od), 0LL);

template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    long long __VA_ARGS__;                                                     \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}

template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18;
const double PI = atan(1.0) * 4.0;
const ll dw[] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dh[] = {0, 1, 1, 1, 0, -1, -1, -1};
#define PI 3.141592653589793238

// 1000000007 で割ったあまりを扱う構造体
template <int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if(val < 0) v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept { return val ? MOD - val : 0; }
    constexpr Fp operator+(const Fp &r) const noexcept {
        return Fp(*this) += r;
    }
    constexpr Fp operator-(const Fp &r) const noexcept {
        return Fp(*this) -= r;
    }
    constexpr Fp operator*(const Fp &r) const noexcept {
        return Fp(*this) *= r;
    }
    constexpr Fp operator/(const Fp &r) const noexcept {
        return Fp(*this) /= r;
    }
    constexpr Fp &operator+=(const Fp &r) noexcept {
        val += r.val;
        if(val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept {
        val -= r.val;
        if(val < 0) val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if(val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os, const Fp<MOD> &x) noexcept {
        return os << x.val;
    }
    friend constexpr istream &operator>>(istream &is, Fp<MOD> &x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if(n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if(n & 1) t = t * a;
        return t;
    }
};

using mint = Fp<MOD>;

ll N, M;
struct edge {
    ll to, cost;
    bool operator<(const edge &another) const { return cost < another.cost; };
    bool operator>(const edge &another) const { return cost > another.cost; };
};
vector<vector<edge>> g;
VL d;
VL cnt;

void dijkstra(ll s) {
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    d.assign(N, LINF);
    cnt.resize(N);
    d[s] = 0, cnt[s] = 1;
    pq.push({s, d[s]});

    while(!pq.empty()) {
        edge now = pq.top();
        pq.pop();
        ll v = now.to;
        if(d[v] < now.cost) continue;
        REP(i, g[v].size()) {
            edge e = g[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                cnt[e.to] = cnt[v];
                pq.push({e.to, d[e.to]});
            } else if(d[e.to] == d[v] + e.cost) {
                cnt[e.to] += cnt[v];
            }
        }
    }
}

mint cntS[100010], cntT[100010];

signed main() {
    cin >> N >> M;
    LCIN(S, T);
    S--, T--;
    g.resize(N);
    VL u(M), v(M), c(M);
    REP(i, M) {
        cin >> u[i] >> v[i] >> c[i];
        u[i]--, v[i]--;
        g[u[i]].push_back({v[i], c[i]});
        g[v[i]].push_back({u[i], c[i]});
    }
    dijkstra(S);
    vector<PL> vec;
    REP(i, N) vec.push_back({d[i], i});
    sort(All(vec));

    cntS[S] = 1;
    REP(i, N) {
        for(edge e : g[vec[i].second]) {
            if(d[vec[i].second] + e.cost == d[e.to]) {
                cntS[e.to] += cntS[vec[i].second];
            }
        }
    }
    cntT[T] = 1;
    for(int i = N - 1; i >= 0; --i) {
        for(edge e : g[vec[i].second]) {
            if(d[vec[i].second] == d[e.to] + e.cost) {
                cntT[e.to] += cntT[vec[i].second];
            }
        }
    }
    mint ans = 0;
    //無視
    ans += cntS[T] * cntT[S];
    //頂点ドーン
    REP(i, N) {
        if(2 * d[i] == d[T]) {
            ans -= cntS[i] * cntS[i] * cntT[i] * cntT[i];
        }
    }
    //辺ドーン
    REP(i, M) {
        if(d[u[i]] > d[v[i]]) swap(u[i], v[i]);
        if(2 * d[u[i]] < d[T] && 2 * d[v[i]] > d[T] && d[u[i]] + c[i] == d[v[i]]) {
            ans -= cntS[u[i]] * cntS[u[i]] * cntT[v[i]] * cntT[v[i]];
        }
    }
    cout << ans << "\n";
}
