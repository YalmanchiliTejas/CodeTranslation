#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define fi first
#define se second
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
#define INF (ll)1e18
#define ll long long
#define P pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define mo (ll)(1e9+7)

vector<vector<P>> g;
ll n, m;
ll s, t;
vll dp, dist;

void mindist(ll a, ll b) {
    dist = vll(n, INF);
    dp = vll(n, 0);
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(0, a)); 
    dist[a] = 0; // "見た"
    dp[a] = 1;
    while (q.size()) { 
        // q = {(d, v)} : 頂点vに距離dで到達できる（dは最適とは限らない）
        // dist[v] : 今までに見た中で、vに到達するための最短距離
        //
        // vの初出がここに来た時点で、dist[v]が最適であることは保証されている！
        // あとは、d = dist[v]のものだけ遷移すれば良い
        P st = q.top(); q.pop();
        ll d = st.fi, v = st.se;
        if (d > dist[v]) continue; // 同じvに異なる距離dで到達可能だが、最適なものだけを見ればよい
        rep(i, g[v].size()) {
            P edge = g[v][i];
            ll u = edge.fi, cost = edge.se;
            if (dist[v] + cost > dist[u]) {
                continue;
            } else if (dist[v] + cost == dist[u]) {
                (dp[u] += dp[v]) %= mo;
            } else {
                dist[u] = dist[v] + cost; // "見た"
                dp[u] = 0;
                (dp[u] += dp[v]) %= mo;
                q.push(P(dist[v] + cost, u));
            }
        }
    }
}

/*
void mindist(ll a, ll b) {
    for (ll i = 0; i < n; i++) saisyou[i] = INF;
    for (ll i = 0; i < n; i++) dp[i] = 0;
//    priority_queue<ll, vll, greater<ll>> q;
    priority_queue<P, vector<P>, greater<P>> q;
    dp[a] = 1, q.push(P(0, a)), saisyou[a] = 0;
    while (q.size()) {
        ll tmp = q.top().se; q.pop();
//        cout << tmp << endl;
        for (ll i = 0; i < g[tmp].size(); i++) {
            if (saisyou[g[tmp][i].fi] == INF || saisyou[tmp] + g[tmp][i].se == saisyou[g[tmp][i].fi]) {
                if (saisyou[g[tmp][i].fi] == INF) { 
                    q.push(P(saisyou[tmp] + g[tmp][i].se, g[tmp][i].fi));
                    saisyou[g[tmp][i].fi] = saisyou[tmp] + g[tmp][i].se;
                }
                dp[g[tmp][i].fi] += dp[tmp];
                dp[g[tmp][i].fi] %= mo;
            }
        }
//        cout << q << endl;
    }
}
*/

vector<P> edges;
int main(void) {
    cin >> n >> m;
    cin >> s >> t; s--, t--;
    g.resize(n);
    dp.resize(n);
    dist.resize(n);
    vvll gg(n);
    for (ll i = 0; i < m; i++) {
        ll u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        edges.pb(P(u, v));
        g[u].push_back(P(v, d)), g[v].push_back(P(u, d));
        gg[u].push_back(v), gg[v].push_back(u);
    }
//    vizGraph(gg,1);

    mindist(t, s);
    vll numt = dp;
    vll dt = dist;

    mindist(s, t);
    vll nums = dp;
    vll ds = dist;

    ll ret = 0;
    // 辺の途中でぶつかる
    rep(v, n) for (auto ud : g[v]) {
        ll u = ud.fi, c = ud.se;
        if (ds[t] == ds[v] + c + dt[u]) {
            if (abs(dt[u] - ds[v]) < c) {
                (ret += nums[v] % mo * numt[u] % mo * nums[v] % mo * numt[u] % mo) %= mo;
            }
        }
    }
    // 頂点でちょうどぶつかる
    rep(i, n) if (dt[i] == ds[i]) {
        (ret += numt[i] % mo * nums[i] % mo * numt[i] % mo * nums[i] % mo) %= mo;
    }

    cout << ((nums[t] % mo * numt[s] % mo - ret) % mo + mo) % mo << endl;

    return 0;
}

