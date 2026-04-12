#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const ll INF = 1e15 + 10;
const ll MOD = 1e9 + 7;

ll dists[N], distt[N];
ll cnts[N], cntt[N];
vector <pair <int, int> > g[N];

void dijkstra(ll* d, ll* cnt, int s, int n) {
    fill(d, d + n, INF);
    vector <bool> used(n, 0);
    d[s] = 0;
    cnt[s] = 1;
    set <pair <ll, int> > st;
    for (int i = 0; i < n; i++)
        if (i != s)
            st.insert(make_pair(INF, i));
    st.insert(make_pair(0, s));
    for (int i = 0; i < n; i++) {
        auto tmp = *st.begin();
        int v = tmp.second;
        for (auto t: g[v])
            if (d[t.second] < INF && d[t.second] + t.first == d[v]) {
                cnt[v] = (cnt[v] + cnt[t.second]);
                if (cnt[v] >= MOD) cnt[v] -= MOD;
            }
        ll w = tmp.first;
        used[v] = true;
        st.erase(st.begin());
        for (auto t: g[v]) {
            if (used[t.second]) continue;
            //assert(st.count(make_pair(d[t.first], t.first)));
            st.erase(make_pair(d[t.second], t.second));
            d[t.second] = min(d[t.second], d[v] + t.first);
            st.insert(make_pair(d[t.second], t.second));
        }
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    int v, u, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v, &u, &w);
        g[--v].pb({w, --u});
        g[u].pb({w, v});
    }
    //for (int i = 0; i <n; i++)for (auto u: g[i]) cout << i << " " << u.second << endl;
    dijkstra(dists, cnts, s, n);
    dijkstra(distt, cntt, t, n);
    ll T = dists[t];
    //cout << T << endl;
//    for (int i = 0; i < n; i++)
//        cout << dists[i] << " ";cout << endl;

    vector <int> verts;
    for (int v = 0; v < n; v++)
        if (dists[v] == distt[v] && 2 * dists[v] == T) {
            verts.pb(v);
            //cout << "v " << v << endl;
        }


    ll ans = cnts[t] * cnts[t] % MOD;
    for (int v = 0; v < n; v++)
        for (auto j: g[v]) {
            int u = j.second;
            if (dists[v] + distt[u] + j.first == T &&
                2 * dists[v] < T && 2 * dists[u] > T)
                ans = (ans - cnts[v] * cntt[u] % MOD * cnts[v] % MOD * cntt[u]) % MOD;
        }

    for (auto v: verts)
        ans = (ans - cnts[v] * cntt[v] % MOD * cnts[v] % MOD * cntt[v]) % MOD;

    cout << (ans + MOD) % MOD << endl;
}
