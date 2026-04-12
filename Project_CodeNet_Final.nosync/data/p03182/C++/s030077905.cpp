#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define sz(a) static_cast<int>((a).size())
#define pb emplace_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second

#ifdef SEREZHKA
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void _dbg(const char* _s, T _h) { cerr << _s << " = " << _h << "\n"; }

template<typename T, typename... Ts>
void _dbg(const char*_s, T _h, Ts... _t) {
    int _b = 0;
    
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++;
    
    cerr << " = " << _h << ",";
    _dbg(_s + 1, _t...);
}

using ll = long long;

const ll INF = static_cast<ll>(1e9) + 7ll;
const ll LINF = INF * INF;
const int MAXN = static_cast<int>(1e6) + 17;

struct segtree {
    int n;
    vector<ll> T, U;

    segtree(int n) : n(n) {
        T.resize(4 * n);
        U.resize(4 * n);
    }

    void push(int v) {
        T[2 * v] += U[v];
        U[2 * v] += U[v];
        T[2 * v + 1] += U[v];
        U[2 * v + 1] += U[v];
        U[v] = 0;
    }

    void upd(int lq, int rq, ll x, int v, int l, int r) {
        if (r < lq || l > rq)
            return ;

        if (lq <= l && r <= rq) {
            T[v] += x;
            U[v] += x;
            return ;
        }

        push(v);
        int m = (l + r) / 2;
        upd(lq, rq, x, 2 * v, l, m);
        upd(lq, rq, x, 2 * v + 1, m + 1, r);
        T[v] = min(T[2 * v], T[2 * v + 1]);
    }

    ll get(int lq, int rq, int v, int l, int r) {
        if (r < lq || l > rq)
            return INF * INF;

        if (lq <= l && r <= rq)
            return T[v];

        push(v);
        int m = (l + r) / 2;
        return min(get(lq, rq, 2 * v, l, m), get(lq, rq, 2 * v + 1, m + 1, r));
    }

    void upd(int lq, int rq, ll x) { upd(lq, rq, x, 1, 0, n - 1); }
    ll get(int lq, int rq) { return get(lq, rq, 1, 0, n - 1); }
};

int n, m;
ll S;
vector< pair<int, int> > v[MAXN];

bool read() {
    if (!(cin >> n >> m))
        return false;

    forn (i, m) {
        int l, r, x;
        cin >> l >> r >> x;
        v[r].pb(mp(l, x));
        S += x;
    }

    return true;
}

void solve() {
    segtree T(n + 2);

    for (int i = 1; i <= n + 1; ++i) {
        auto cur = T.get(0, i - 1);
        T.upd(i, i, cur);

        if (i == n + 1)
            cout << S - cur << endl;

        for (auto p : v[i])
            T.upd(0, p.f - 1, p.s);
    }
}

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
#ifdef SEREZHKA
    freopen("file.in", "r", stdin);
#endif
    
    while (read())
        solve();
    
    return 0;
}

