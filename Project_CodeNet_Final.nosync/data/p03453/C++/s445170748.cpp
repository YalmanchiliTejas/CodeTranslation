#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;

using int64 = long long;
using P = pair<int64, int>;

const int64 MOD = 1e9 + 7;

struct Edge {
    int to;
    int64 cost;
};

int N, M, S, T;

const int MAX_N = 200000;
const int64 INF = (1LL << 60);

vector<Edge> G[MAX_N];
int64 cost_s[MAX_N], cost_t[MAX_N];
int64 num_s[MAX_N], num_t[MAX_N];

void dijkstra_s() {
    fill(cost_s, cost_s + MAX_N, INF);
    priority_queue<P, vector<P>, greater<P>> Q;
    cost_s[S] = 0;
    Q.push(make_pair(0, S));
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (cost_s[p.second] < p.first) continue;

        for (Edge& e: G[p.second]) {
            if (cost_s[e.to] > p.first + e.cost) {
                cost_s[e.to] = p.first + e.cost;
                Q.push(make_pair(cost_s[e.to], e.to));
            }
        }
    }
}

void dijkstra_t() {
    fill(cost_t, cost_t + MAX_N, INF);
    priority_queue<P, vector<P>, greater<P>> Q;
    cost_t[T] = 0;
    Q.push(make_pair(0, T));
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (cost_t[p.second] < p.first) continue;

        for (Edge& e: G[p.second]) {
            if (cost_t[e.to] > p.first + e.cost) {
                cost_t[e.to] = p.first + e.cost;
                Q.push(make_pair(cost_t[e.to], e.to));
            }
        }
    }
}

void enumerate_s() {
    priority_queue<P, vector<P>, greater<P>> Q;
    num_s[S] = 1;
    Q.push({0, S});
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();

        for (Edge& e : G[p.second]) {
            if (cost_s[p.second] + e.cost + cost_t[e.to] == cost_s[T]) {
                if (num_s[e.to] == 0) Q.push({cost_s[e.to], e.to});
                (num_s[e.to] += num_s[p.second]) %= MOD;
            }
        }
    }
}

void enumerate_t() {
    priority_queue<P, vector<P>, greater<P>> Q;
    num_t[T] = 1;
    Q.push({0, T});
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();

        for (Edge& e : G[p.second]) {
            if (cost_t[p.second] + e.cost + cost_s[e.to] == cost_s[T]) {
                if (num_t[e.to] == 0) Q.push({cost_t[e.to], e.to});
                (num_t[e.to] += num_t[p.second]) %= MOD;
            }
        }
    }
}

int main() {
    cin >> N >> M >> S >> T;
    S--; T--;

    vector<tuple<int, int, int64>> E;
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        G[u].push_back((Edge){v, d});
        G[v].push_back((Edge){u, d});

        E.emplace_back(u, v, d);
    }

    dijkstra_s();
    dijkstra_t();
    enumerate_s();
    enumerate_t();

    int64 ans = (num_s[T] * num_t[S]) % MOD;
    for (int v = 0; v < N; v++) {
        if (v == S or v == T) continue;
        if (cost_s[v] == cost_t[v]) {
            int64 a = (num_s[v] * num_t[v]) % MOD;
            ans = (ans - (a * a) % MOD + MOD) % MOD;
        }
    }

    for (auto e : E) {
        int u = get<0>(e);
        int v = get<1>(e);
        int64 d = get<2>(e);
        if (cost_s[u] > cost_s[v]) swap(u, v);
        if (cost_s[u] + d + cost_t[v] != cost_s[T]) continue;
        if (abs(cost_s[u] - cost_t[v]) < d) {
            int64 a = (num_s[u] * num_t[v]) % MOD;
            ans = (ans - (a * a) % MOD + MOD) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}