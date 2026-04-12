#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct State {
    int at;
    ll cost;
    int prev;
    State(int at, ll cost, int prev) : at(at), cost(cost), prev(prev) {}
    bool operator>(const State& s) const {
        if (cost != s.cost) return cost > s.cost;
        if (prev != s.prev) return prev > s.prev; //最短経路を辞書順最小にする(省略可)
        return at > s.at;
    }
};

struct Edge {
  int to;
  ll cost;
  Edge(int to, ll cost) : to(to), cost(cost) {}
};

typedef vector<vector<Edge> > AdjList; //隣接リスト

const ll INF = 10000000000000000LL;
const int NONE = -1;

AdjList graph;

//sは始点、mincは最短経路のコスト、Prevは最短経路をたどる際の前の頂点
void dijkstra(int s, vector<ll>& minc, vector<int>& Prev){
    priority_queue<State, vector<State>, greater<State> > pq;
    pq.push(State(s, 0, NONE));
    while(!pq.empty()) {
        State cur = pq.top();
        pq.pop();
        if (minc[cur.at] <= cur.cost) continue;
        minc[cur.at] = cur.cost;
        Prev[cur.at] = cur.prev;
        for(Edge e : graph[cur.at]) {
            ll cost = cur.cost + e.cost;
            if (minc[e.to] <= cost) continue;
            pq.push(State(e.to, cost, cur.at));
        }
    }
}

const ll MOD = 1000000007;

void solve(int src, vector<ll>& minc, AdjList& g, vector<ll>& dp) {
    vector<int> idxs(minc.size());
    for (int i = 0; i < minc.size(); i++) idxs[i] = i;
    sort(idxs.begin(), idxs.end(), [&](const int& i1, const int& i2){return minc[i1] < minc[i2];});
    dp[src] = 1;
    for (int i : idxs) {
        for (Edge& e : g[i]) {
            (dp[e.to] += dp[i]) %= MOD;
        }
    }
}

/*
ll modpow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<int> u(m), v(m);
    vector<ll> d(m);
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> d[i];
        u[i]--;
        v[i]--;
        graph[u[i]].emplace_back(v[i], d[i]);
        graph[v[i]].emplace_back(u[i], d[i]);
    }
    vector<ll> minc(n, INF);
    vector<ll> mincr(n, INF);
    vector<int> Prev(n, NONE);
    vector<int> Prev2(n, NONE);
    dijkstra(s, minc, Prev);
    dijkstra(t, mincr, Prev2);

    AdjList g(n), rg(n);
    for (int i = 0; i < m; i++) {
        ll tmp = abs(minc[u[i]] - minc[v[i]]);
        if (tmp != d[i]) continue;
        if (minc[u[i]] < minc[v[i]]) {
            g[u[i]].emplace_back(v[i], d[i]);
            //rg[v[i]].emplace_back(u[i], d[i]);
        }
        else {
            g[v[i]].emplace_back(u[i], d[i]);
            //rg[u[i]].emplace_back(v[i], d[i]);
        }
    }

    for (int i = 0; i < m; i++) {
        ll tmp = abs(mincr[u[i]] - mincr[v[i]]);
        if (tmp != d[i]) continue;
        if (mincr[u[i]] < mincr[v[i]]) {
            rg[u[i]].emplace_back(v[i], d[i]);
            //rg[v[i]].emplace_back(u[i], d[i]);
        }
        else {
            rg[v[i]].emplace_back(u[i], d[i]);
            //rg[u[i]].emplace_back(v[i], d[i]);
        }
    }

    vector<ll> dp(n, 0), dpr(n, 0);
    
    solve(s, minc, g, dp);
    solve(t, mincr, rg, dpr);

    ll ans = dp[t] * dp[t] % MOD;
    for (int i = 0; i < m; i++) {
        ll tmp = abs(minc[u[i]] - minc[v[i]]);
        if (tmp != d[i]) continue;
        if (minc[u[i]] > minc[v[i]]) swap(u[i], v[i]);
        if (abs(minc[u[i]] - mincr[v[i]]) < d[i] && minc[u[i]] + mincr[v[i]] + d[i] == minc[t]) {
            ans = (ans + MOD - dp[u[i]] * dpr[v[i]] % MOD * dp[u[i]] % MOD * dpr[v[i]] % MOD) % MOD;
        }
    }

    for (int i = 0; i < n; i++) {
        if (minc[i] * 2 == minc[t]) {
            ans = (ans + MOD - dp[i] * dpr[i] % MOD * dp[i] % MOD * dpr[i] % MOD) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}