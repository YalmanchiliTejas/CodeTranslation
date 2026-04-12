#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// }}}

using ll = long long;

#define sq(x) ((x)*(x))

ll INF = 1LL << 60;

ll MOD = 1000000007LL;

struct edge {
    int to; ll dist;
    edge() {} ~edge() {}
    edge(int to, ll dist): to(to), dist(dist) {}
};

struct state {
    int v; ll cost;
    state() {} ~state() {}
    state(int v, ll cost): v(v), cost(cost) {}
    bool operator < (const state& o) const { return cost > o.cost; }
};

int N, M, S, T;
vector<vector<edge>> graph;
vector<tuple<int, int, int>> edges;

vector<ll> min_cost;
vector<ll> num;

void calc(int start, int goal) {
    fill(begin(min_cost), end(min_cost), INF);
    fill(begin(num), end(num), 0);

    min_cost[start] = 0;
    num[start] = 1;

    priority_queue<state> pq;
    pq.emplace(start, 0);
    while (!pq.empty()) {
        state s = pq.top(); pq.pop();
        if (min_cost[s.v] < s.cost) continue;
        for (int i = 0; i < graph[s.v].size(); ++i) {
            edge& e = graph[s.v][i];
            ll cost = s.cost + e.dist;
            if (cost < min_cost[e.to]) {
                min_cost[e.to] = cost;
                num[e.to] = num[s.v];
                pq.emplace(e.to, cost);
            } else if (cost == min_cost[e.to]) {
                num[e.to] = (num[e.to] + num[s.v]) % MOD;
            }
        }
    }
}

int main() {

    cin >> N >> M >> S >> T;
    --S; --T;
    min_cost.resize(N);
    num.resize(N);
    graph.resize(N);
    for (int j = 0; j < M; ++j) {
        int u, v; ll d; cin >> u >> v >> d; --u; --v;
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d);
        edges.emplace_back(u, v, d);
    }

    calc(S, T);
    vector<ll> min_cost1 = min_cost;
    vector<ll> num1 = num;
    calc(T, S);
    vector<ll> min_cost2 = min_cost;
    vector<ll> num2 = num;

    ll dd = min_cost1[T];

    ll ans = sq(num1[T]) % MOD;
    for (int j = 0; j < N; ++j) {
        if (min_cost1[j] + min_cost2[j] == dd && min_cost1[j] == min_cost2[j]) {
            ans = (ans - sq(num1[j]*num2[j]%MOD)%MOD + MOD) % MOD;
        }
    }

    for (auto e : edges) {
        int u, v, d;
        tie(u, v, d) = e;
        if (min_cost1[u] > min_cost1[v]) swap(u, v);
        if (min_cost1[u] + d + min_cost2[v] == dd &&
                min_cost1[u] < (double) dd / 2 && min_cost2[v] < (double) dd / 2) {
            ans = (ans - sq(num1[u]*num2[v]%MOD)%MOD + MOD) % MOD;
        }
    }
    cout << ans << endl;



    return 0;
}


