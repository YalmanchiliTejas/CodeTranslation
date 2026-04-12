#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

constexpr ll INF = LLONG_MAX / 2;

struct Edge {
    ll to, cost;
};
vector<vector<Edge>> edges;

struct Element {
    ll node, cost;
    bool operator<(const Element& rhs) const {
        return cost < rhs.cost;
    }
    bool operator>(const Element& rhs) const {
        return cost > rhs.cost;
    }
};

vector<ll> dijkstra(const vector<vector<Edge>>& edges, ll s) {
    vector<ll> cost(edges.size(), INF);
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    cost[s] = 0;
    pq.push({ s, 0 });
    while (!pq.empty()) {
        Element t = pq.top();
        pq.pop();
        if (t.cost > cost[t.node]) {
            continue;
        }

        for (const Edge& edge : edges[t.node]) {
            ll new_cost = t.cost + edge.cost;
            if (new_cost < cost[edge.to]) {
                cost[edge.to] = new_cost;
                pq.push({ edge.to, new_cost });
            }
        }
    }

    return cost;
}

constexpr ll MOD = (ll)1e9 + 7;

vector<ll> numOfShortestPath(const vector<vector<Edge>>& edges, ll s) {
    vector<ll> cost(edges.size(), INF);
    priority_queue<Element, vector<Element>, greater<Element>> pq;
    vector<ll> dp(edges.size(), 0);

    cost[s] = 0;
    dp[s] = 1;
    pq.push({ s, 0 });
    while (!pq.empty()) {
        Element t = pq.top();
        pq.pop();
        if (t.cost > cost[t.node]) {
            continue;
        }

        for (const Edge& edge : edges[t.node]) {
            ll new_cost = t.cost + edge.cost;
            if (new_cost < cost[edge.to]) {
                cost[edge.to] = new_cost;
                pq.push({ edge.to, new_cost });
                dp[edge.to] = dp[t.node];
            } else if (new_cost == cost[edge.to]) {
                (dp[edge.to] += dp[t.node]) %= MOD;
            }
        }
    }

    return dp;
}

int main() {
    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--; T--;

    edges.resize(N);
    for (ll i = 0; i < M; i++) {
        ll U, V, D;
        cin >> U >> V >> D;
        U--; V--;
        edges[U].push_back({ V, D });
        edges[V].push_back({ U, D });
    }

    auto dS = dijkstra(edges, S);
    auto dT = dijkstra(edges, T);
    auto dp1 = numOfShortestPath(edges, S);
    auto dp2 = numOfShortestPath(edges, T);

    auto squareMOD = [&](ll x) {
        return x * x % MOD;
    };

    ll ans = squareMOD(dp1[T]);
    for (ll u = 0; u < N; u++) {
        //頂点上で出会う
        if (2 * dS[u] == dS[T]) {
            ans = (ans - squareMOD(dp1[u]) * squareMOD(dp2[u]) % MOD + MOD) % MOD;
        }

        for (Edge edge : edges[u]) {
            //辺上で出会う
            ll v = edge.to;
            if (2 * dS[u] < dS[T] && 2 * dS[v] > dS[T] && dS[u] + edge.cost + dT[v] == dS[T]) {
                ans = (ans - squareMOD(dp1[u]) * squareMOD(dp2[v]) % MOD + MOD) % MOD;
            }
        }
    }

    cout << ans << endl;
}