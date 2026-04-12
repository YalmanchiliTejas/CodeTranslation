#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1 << 30;
template <typename Functor>
struct fix_type
{
    Functor functor;
    template <typename... Args>
    decltype(auto) operator()(Args&&... args) const& { return functor(functor, std::forward<Args>(args)...); }
};
template <typename Functor>
fix_type<typename std::decay<Functor>::type> fix(Functor&& functor) { return {std::forward<Functor>(functor)}; }
class Flow
{
public:
    struct Edge
    {
        int from, to, revind, capacity, flow;
        bool reversed;
    };
    Flow(const int v) : V{v}, edge(v) {}
    void addEdge(const int from, const int to, const int capacity) { edge[from].push_back(Edge{from, to, (int)edge[to].size(), capacity, 0, false}), edge[to].push_back(Edge{to, from, (int)edge[from].size() - 1, capacity, capacity, true}); }
    int FordFulkerson(const int s, const int t)
    {
        vector<bool> checked(V);
        auto dfs = fix([&](auto&& self, const int pos, const int& flow) -> int {
            if (pos == t) { return flow; }
            checked[pos] = true;
            for (auto& e : edge[pos]) {
                if (not checked[e.to]) {
                    const int res = e.capacity - e.flow;
                    if (res > 0) {
                        const int d = self(self, e.to, min(flow, res));
                        if (d > 0) {
                            e.flow += min(d, res), edge[e.to][e.revind].flow -= min(d, res);
                            return d;
                        }
                    }
                }
            }
            return 0;
        });
        int flow = 0;
        while (true) {
            for (int i = 0; i < V; i++) { checked[i] = false; }
            const int f = dfs(s, INF);
            if (f == 0) { break; }
            flow += f;
        }
        return flow;
    }
    const int V;
    vector<vector<Edge>> edge;
};
int main()
{
    for (int N, M;;) {
        cin >> N >> M;
        if (N == 0 and M == 0) { break; }
        Flow flow(N + M + 2);
        const int S = N + M, T = N + M + 1;
        for (int i = 0, u, v; i < M; i++) { cin >> u >> v, u--, v--, flow.addEdge(u, i + N, 1), flow.addEdge(v, i + N, 1); }
        for (int i = N; i < N + M; i++) { flow.addEdge(i, T, 1); }
        int inf = M / N;
        for (; inf >= 0; inf--) {
            auto f = flow;
            for (int i = 0; i < N; i++) { f.addEdge(S, i, inf); }
            const int F = f.FordFulkerson(S, T);
            if (F >= inf * N) { break; }
        }
        int sup = inf;
        for (;; sup++) {
            auto f = flow;
            for (int i = 0; i < N; i++) { f.addEdge(S, i, sup); }
            const int F = f.FordFulkerson(S, T);
            if (F >= M) { break; }
        }
        cout << inf << " " << sup << endl;
    }
    return 0;
}

