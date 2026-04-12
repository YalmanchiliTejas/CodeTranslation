#include "bits/stdc++.h"
using namespace std;
typedef long long li;

const li mod = 1e9 + 7;

struct Result {
    vector<li> dists;
    vector<li> counts;
};

struct Edge {
    li to;
    li dist;
};

Result dp(const vector<vector<Edge>>& graph, li s, li t) {
    const int n = graph.size();
    vector<li> dists(n, 1LL << 55);
    vector<bool> visit(n);
    vector<li> counts(n, 0);
    counts[s] = 1;
    dists[s] = 0;

    priority_queue<pair<li, li>> q;
    q.emplace(0, s);
    while (not q.empty()) {
        auto f = q.top(); q.pop();
        li cost = -f.first;
        li pos = f.second;

        if (visit[pos]) {
            continue;
        }
        visit[pos] = true;
        for (auto &&edge : graph[pos]) {
            li next_pos = edge.to;
            li next_cost = cost + edge.dist;

            if (next_cost < dists[next_pos]) {
                counts[next_pos] = counts[pos];
                dists[next_pos] = next_cost;
                q.emplace(-next_cost, next_pos);
            } else if (next_cost == dists[next_pos]) {
                counts[next_pos] = (counts[next_pos] + counts[pos]) % mod;
                q.emplace(-next_cost, next_pos);
            }
        }
    }
    return (Result) {dists, counts};
}

int main() {
    li n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;

    vector<vector<Edge>> graph(n);
    vector<li> fr(m), to(m), dists(m);
    for (int i = 0; i < m; ++i) {
        li u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        fr[i] = u;
        to[i] = v;
        dists[i] = d;
        graph[u].push_back((Edge) {v, d});
        graph[v].push_back((Edge) {u, d});
    }

    Result takahashi = dp(graph, s, t);
    Result aoki = dp(graph, t, s);

    li dist = takahashi.dists[t];
    li ans = takahashi.counts[t] * aoki.counts[s] % mod;
    for (int i = 0; i < n; ++i) {
        if (takahashi.dists[i] + aoki.dists[i] > dist) {
            continue;
        }
        if (takahashi.dists[i] != aoki.dists[i]) {
            continue;
        }
        li path_count = takahashi.counts[i] * aoki.counts[i] % mod;
        li comb_count = path_count * path_count % mod;
        ans = (ans - comb_count + mod) % mod;
    }

    for (int i = 0; i < m; ++i) {
        li takahashi_idx, aoki_idx;
        if (takahashi.dists[fr[i]] + dists[i] + aoki.dists[to[i]] == dist) {
            takahashi_idx = fr[i];
            aoki_idx = to[i];
        } else if (aoki.dists[fr[i]] + dists[i] + takahashi.dists[to[i]] == dist) {
            aoki_idx = fr[i];
            takahashi_idx = to[i];
        } else {
            continue;
        }

        li takahashi_start = takahashi.dists[takahashi_idx];
        li aoki_start = aoki.dists[aoki_idx];
        li takahashi_end = takahashi_start + dists[i];
        li aoki_end = aoki_start + dists[i];

        if (takahashi_end <= aoki_start || aoki_end <= takahashi_start) {
            continue;
        }
        li path_count = takahashi.counts[takahashi_idx] * aoki.counts[aoki_idx] % mod;
        li comb_count = path_count * path_count % mod;
        ans = (ans - comb_count + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}