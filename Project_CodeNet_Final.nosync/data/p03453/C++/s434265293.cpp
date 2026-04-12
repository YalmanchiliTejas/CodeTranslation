#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> TEdge;
const int N = int(2e5) + 7;
const int mod = int(1e9) + 7;
const ll oo = (ll)1e18;

void sub(int& x, int y) {if((x -= y) < 0) x += mod;}
void add(int& x, int y) {if((x += y) >= mod) x -= mod;}
int mul(int x, int y) {return 1ll * x * y % mod;}

int n, m, s, t, u, v, w;
TEdge e[N];
vector<ll> d[2];
vector<int> cnt[2];
vector<pii> a[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void Dijkstra(int s, vector<ll>& d, vector<int>& cnt) {
    d.resize(n + 1, oo), cnt.resize(n + 1, 0);
    d[s] = 0; cnt[s] = 1; pq.push(mp(0, s));
    while(pq.size()) {
        pii top = pq.top(); pq.pop();
        if(top.fi != d[top.se]) continue;
        for(pii p: a[top.se]) {
            if(d[p.se] > top.fi + p.fi) {
                d[p.se] = top.fi + p.fi;
                cnt[p.se] = cnt[top.se];
                pq.push(mp(d[p.se], p.se));
            } else if(d[p.se] == top.fi + p.fi) add(cnt[p.se], cnt[top.se]);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> m >> s >> t;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        a[u].pb(w, v), a[v].pb(w, u);
        e[i] = make_tuple(u, v, w);
    }
    Dijkstra(s, d[0], cnt[0]), Dijkstra(t, d[1], cnt[1]);
    ll dis = d[0][t], du, dv; int res = mul(cnt[0][t], cnt[0][t]);
    for(int i = 1; i <= n; ++i)
        if(d[0][i] * 2 == dis && d[0][i] + d[1][i] == d[0][t]) sub(res, mul(mul(cnt[0][i], cnt[0][i]), mul(cnt[1][i], cnt[1][i])));
    for(int i = 0; i < m; ++i) {
        tie(u, v, w) = e[i];
        du = d[0][u], dv = d[1][v];
        if(du * 2 < dis && dv * 2 < dis && du + dv + w == dis) sub(res, mul(mul(cnt[0][u], cnt[0][u]), mul(cnt[1][v], cnt[1][v])));
        swap(u, v);
        du = d[0][u], dv = d[1][v];
        if(du * 2 < dis && dv * 2 < dis && du + dv + w == dis) sub(res, mul(mul(cnt[0][u], cnt[0][u]), mul(cnt[1][v], cnt[1][v])));
    }
    cout << res;
}
