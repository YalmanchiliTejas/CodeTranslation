// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //
// 🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤🖤 //

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 1e5 + 1;
const ll INF = 1e16, MOD = 1e9 + 7;
vector<pll> g[MAXN];
ll ds[MAXN], dt[MAXN];

void dijkstra(int s, int n, ll * d) {
    set<pll> bang;
    for (int i = 1; i <= n; ++i) {
        d[i] = i == s ? 0 : INF;
        bang.insert({d[i], i});
    }
    while (!bang.empty()) {
        pll pv = *bang.begin();
        bang.erase(pv);
        int v = pv.ss;
        for (pll e : g[v]) {
            if (d[e.ff] > d[v] + e.ss) {
                bang.erase({d[e.ff], e.ff});
                bang.insert({d[e.ff] = d[v] + e.ss, e.ff});
            }
        }
    }
}

vector<pll> gs[MAXN], gt[MAXN];
vector<int> order;
ll cs[MAXN], ct[MAXN];

inline ll add(ll a, ll b) {return (a + b) % MOD;}
inline ll sub(ll a, ll b) {return (a - b + MOD) % MOD;}
inline ll mul(ll a, ll b) {return (a * b) % MOD;}

bool used[MAXN];
void topsort(int v, vector<pll> * gg) {
    used[v] = 1;
    for (pll to : gg[v])
        if (!used[to.ff])
            topsort(to.ff, gg);
    order.pb(v);
}

int main() {
    
    int n = 100000, m=99999, s=1, t=100000;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int a=i+1, b=i+2, c=1;
        cin >> a >> b >> c;
        g[a].pb(b, c);
        g[b].pb(a, c);
    }

    dijkstra(s, n, ds);
    dijkstra(t, n, dt);

    for (int i = 1; i <= n; ++i)
        dbg(i, ds[i], dt[i]);

    ll len = ds[t];

    for (int i = 1; i <= n; ++i)
        for (pll e : g[i]) {
            if (ds[i] + e.ss + dt[e.ff] == len) {
                gs[i].pb(e);
                gt[e.ff].pb(i, e.ss);
            }
        }

    memset(used, 0, sizeof used);
    topsort(s, gs);
    ct[t] = 1;
    for (int v : order) {
        for (pll to : gs[v])
            ct[v] = add(ct[v], ct[to.ff]);
        dbg(v, ct[v]);
    }
    order.clear();
    memset(used, 0, sizeof used);
    topsort(t, gt);
    cs[s] = 1;
    for (int v : order) {
        for (pll to : gt[v])
            cs[v] = add(cs[v], cs[to.ff]);
        dbg(v, cs[v]);
    }

    assert(ct[s] == cs[t]);

    ll ans = mul(cs[t], cs[t]);
    dbg(ans);
    for (int i = 1; i <= n; ++i)
        if (ds[i] == dt[i] && ds[i] + dt[i] == len)
            ans = sub(ans, mul(mul(cs[i], ct[i]), mul(cs[i], ct[i])));

    dbg(ans, "vertex");

    for (int i = 1; i <= n; ++i)
        for (pll e : gs[i]) {
            int to = e.ff;
            if (ds[i] + e.ss + dt[to] == len && ds[i] + ds[i] < len && dt[to] + dt[to] < len) {
                ans = sub(ans, mul(mul(cs[i], ct[to]), mul(cs[i], ct[to])));
            }
        }

    cout << ans << '\n';
    
    return 0;
}
