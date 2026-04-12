#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt(x) __builtin_popcount(x)
#define lbit(x) __builtin_ffsll(x)
#define rbit(x) __builtin_clzll(x)
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
#define PERM(c)                                                                \
    sort(All(c));                                                              \
    for(bool cp = true; cp; cp = next_permutation(All(c)))
#define MKORDER(n)                                                             \
    vector<ll> od(n);                                                          \
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
    ll __VA_ARGS__;                                                            \
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

// generic lambdas
template <typename F>
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) &&                                                     \
    (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    static inline constexpr decltype(auto)
    fix(F &&f) noexcept {
    return [f = std::forward<F>(f)](auto &&... args) {
        return f(f, std::forward<decltype(args)>(args)...);
    };
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

signed main() {
    LCIN(N);
    ll midx, Midx;
    ll m = LINF, M = -LINF;
    VL x(N), y(N);
    REP(i, N) {
        cin >> x[i] >> y[i];
        ll mi = min(x[i], y[i]);
        ll ma = max(x[i], y[i]);
        if(mi < m) {
            midx = i;
            m = mi;
        }
        if(ma > M) {
            Midx = i;
            M = ma;
        }
    }
    ll ans = LINF;
    VL r, b;
    r.emplace_back(max(x[Midx], y[Midx]));
    b.emplace_back(min(x[Midx], y[Midx]));
    if(midx != Midx) {
        r.emplace_back(max(x[midx], y[midx]));
        b.emplace_back(min(x[midx], y[midx]));
    }
    REP(i, N) {
        if(i == midx || i == Midx) continue;
        r.emplace_back(max(x[i], y[i]));
        b.emplace_back(min(x[i], y[i]));
    }
    sort(All(r));
    sort(All(b));
    ans = min(ans, (r.back() - r[0]) * (b.back() - b[0]));
    if(Midx == midx) eputs(ans);
    r.clear();
    b.clear();
    r.emplace_back(max(x[Midx], y[Midx]));
    r.emplace_back(min(x[midx], y[midx]));
    b.emplace_back(min(x[Midx], y[Midx]));
    b.emplace_back(max(x[midx], y[midx]));
    MKORDER(N);
    sort(All(od),
         [&](ll a, ll b) { return min(x[a], y[a]) < min(x[b], y[b]); });
    multiset<ll> st;
    st.emplace(b[0]);
    st.emplace(b[1]);
    REP(i, N) {
        ll idx = od[i];
        if(idx == midx || idx == Midx) continue;
        ll mi = min(x[idx], y[idx]);
        ll ma = max(x[idx], y[idx]);
        st.emplace(mi);
    }
    REP(i, N) {
        ll idx = od[i];
        if(idx == midx || idx == Midx) continue;
        ll mi = min(x[idx], y[idx]);
        ll ma = max(x[idx], y[idx]);
        if(*st.begin() != mi) break;
        ll dif = ma - *(--st.end());
        ll dif2 = *(++st.begin()) - *(st.begin());
        if(dif <= dif2) {
            st.erase(st.begin());
            st.emplace(ma);
        }
    }
    sort(All(r));
    ans = min(ans, (r.back() - r[0]) * (*(--st.end()) - *st.begin()));
    cout << ans << "\n";
}
