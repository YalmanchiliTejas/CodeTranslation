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
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()
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
#define Printv(v)                                                              \
    {                                                                          \
        REP(x, v.size()) { cout << v[x] << (x == v.size() - 1 ? "\n" : " "); } \
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
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<double> VD;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};
#define PI 3.141592653589793238

// size用
struct UnionFind {
    vector<ll> par;
    vector<ll> sizes;

    UnionFind(ll n) : par(n), sizes(n, 1) { REP(i, n) par[i] = i; }

    ll find(ll x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);

        if(x == y) return;

        if(sizes[x] < sizes[y]) swap(x, y);

        par[y] = x;
        sizes[x] += sizes[y];
        sizes[y] = 0;
    }

    bool same(ll x, ll y) { return find(x) == find(y); }

    ll size(ll x) { return sizes[find(x)]; }
};

set<ll> st;

signed main() {
    LCIN(N);
    SCIN(s);
    VL ans(N);
    REP(i, 2) REP(j, 2) {
        ans[0] = i, ans[1] = j;
        FOR(k, 2, N) {
            if(s[k - 1] == 'o' && ans[k - 1] == 0)
                ans[k] = ans[k - 2];
            else if(s[k - 1] == 'x' && ans[k - 1] == 0)
                ans[k] = (ans[k - 2] ^ 1);
            else if(s[k - 1] == 'o' && ans[k - 1] == 1)
                ans[k] = (ans[k - 2] ^ 1);
            else if(s[k - 1] == 'x' && ans[k - 1] == 1)
                ans[k] = ans[k - 2];
        }
        if(s[0] == 'o' && ans[0] == 0 && ans[1] != ans[N - 1])
            continue;
        else if(s[0] == 'x' && ans[0] == 0 && ans[1] == ans[N - 1])
            continue;
        else if(s[0] == 'o' && ans[0] == 1 && ans[1] == ans[N - 1])
            continue;
        else if(s[0] == 'x' && ans[0] == 1 && ans[1] != ans[N - 1])
            continue;
        if(s[N - 1] == 'o' && ans[N - 1] == 0 && ans[0] != ans[N - 2])
            continue;
        else if(s[N - 1] == 'x' && ans[N - 1] == 0 && ans[0] == ans[N - 2])
            continue;
        else if(s[N - 1] == 'o' && ans[N - 1] == 1 && ans[0] == ans[N - 2])
            continue;
        else if(s[N - 1] == 'x' && ans[N - 1] == 1 && ans[0] != ans[N - 2])
            continue;
        REP(k, N) { cout << (ans[k] ? "W" : "S"); }
        cout << "\n";
        exit(0);
    }
    eputs(-1);
}
