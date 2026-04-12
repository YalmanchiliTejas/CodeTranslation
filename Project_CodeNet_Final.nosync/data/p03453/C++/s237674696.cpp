#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

using Graph = vector<vector<pair<int64_t, int64_t>>>;

struct PathsData
{
    vector<int64_t> costs;
    vector<int64_t> paths;
};

constexpr int64_t kMod = 1e9 + 7;

PathsData Dijkstra(const Graph &g, int start)
{
    vector<int64_t> costs(g.size(), (1LL << 60));
    vector<int64_t> paths(g.size(), 0);

    costs[start] = 0;
    paths[start] = 1;

    MinHeap<pair<int64_t, int64_t>> q;
    q.push({0, start});

    while (!q.empty()) {
        auto cost = q.top().first;
        auto node = q.top().second;
        q.pop();

        if (cost != costs[node]) {
            continue;
        }

        for (const auto &e : g[node]) {
            auto new_node = e.first;
            auto new_cost = cost + e.second;

            if (new_cost < costs[new_node]) {
                costs[new_node] = new_cost;
                paths[new_node] = paths[node];
                q.push({new_cost, new_node});
            } else if (new_cost == costs[new_node]) {
                paths[new_node] = (paths[new_node] + paths[node]) % kMod;
            }
        }
    }
    return PathsData{costs, paths};
}

int64_t CalcBadPairs(const Graph &g, int node1, int node2,
                    const PathsData &p1, const PathsData &p2)
{
    int64_t bad = p1.paths[node2];
    auto min_cost = p1.costs[node2];

    for (size_t i = 0; i < g.size(); i += 1) {
        if (p1.costs[i] == p2.costs[i] && 2 * p1.costs[i] == min_cost) {
            auto paths = (p1.paths[i] * p2.paths[i]) % kMod;
            bad += (paths * (paths - 1)) % kMod;
            bad %= kMod;
        }
    }

    for (size_t i = 0; i < g.size(); i += 1) {
        for (const auto &e : g[i]) {
            auto next = e.first;
            auto cost = p1.costs[i] + p2.costs[next] + e.second;
            auto aux1 = p1.costs[i] + e.second;
            auto aux2 = p2.costs[next] + e.second;

            if (aux1 > p2.costs[next] && aux2 > p1.costs[i] && cost == min_cost) {
                auto paths = (p1.paths[i] * p2.paths[next]) % kMod;
                bad += (paths * (paths - 1)) % kMod;
                bad %= kMod;
            }
        }
    }

    return bad;
}

int64_t Solve(const Graph &g, int node1, int node2)
{
    auto paths_node1 = Dijkstra(g, node1);
    auto paths_node2 = Dijkstra(g, node2);

    auto bad_pairs = CalcBadPairs(g, node1, node2, paths_node1, paths_node2);

    auto total_pairs = (paths_node1.paths[node2] % kMod) *
                       (paths_node2.paths[node1] % kMod) % kMod;

    auto res = total_pairs - bad_pairs;
    while (res < 0) {
        res += kMod;
    }

    return res;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    int node1, node2;
    cin >> node1 >> node2;

    Graph graph(nodes);
    for (auto i = 0; i < edges; i += 1) {
        int64_t a, b, cost;
        cin >> a >> b >> cost;

        graph[a - 1].push_back({b - 1, cost});
        graph[b - 1].push_back({a - 1, cost});
    }

    auto res = Solve(graph, node1 - 1, node2 - 1);
    cout << res << "\n";

    return 0;
}
