#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for (ll i = (a); i > (b); --i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOREACH(x, a) for (auto &(x) : (a))
#define VECCIN(x)            \
    for (auto &youso_ : (x)) \
    cin >> youso_
#define bitcnt(x) __builtin_popcount(x)
#define lbit(x) __builtin_ffsll(x)
#define rbit(x) __builtin_clzll(x)
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
#define PERM(c)   \
    sort(All(c)); \
    for (bool cp = true; cp; cp = next_permutation(All(c)))
#define MKORDER(n)    \
    vector<ll> od(n); \
    iota(All(od), 0LL);

template <typename T = long long>
inline T IN()
{
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail)
{
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)     \
    char __VA_ARGS__; \
    CIN(__VA_ARGS__)
#define DCIN(...)       \
    double __VA_ARGS__; \
    CIN(__VA_ARGS__)
#define LCIN(...)   \
    ll __VA_ARGS__; \
    CIN(__VA_ARGS__)
#define SCIN(...)       \
    string __VA_ARGS__; \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                           \
    {                                       \
        FOREACH(x, v) { cout << x << " "; } \
        cout << "\n";                       \
    }
template <typename T = string>
inline void eputs(T s)
{
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
    std::fill((T *)array, (T *)(array + N), val);
}

// generic lambdas
template <typename F>
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && \
    (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    static inline constexpr decltype(auto)
    fix(F &&f) noexcept
{
    return [f = std::forward<F>(f)](auto &&... args) {
        return f(f, std::forward<decltype(args)>(args)...);
    };
}

template <typename T>
using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using PQ = priority_queue<T>;

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

signed main()
{
    LCIN(N);
    VL a(N);
    VECCIN(a);
    ll res=0;
    while(1){
        bool update = false;
        REP(i,N){
            if(a[i]<N) continue;
            update=true;
            ll di = a[i]/N;
            a[i]=a[i]%N;
            res+=di;
            REP(j,N) if(i!=j) a[j]+=di;
        }
        if(!update) break;
    }
    cout << res << "\n";
}
