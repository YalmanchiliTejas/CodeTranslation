#include <iostream>
#include <vector>

using namespace std;

using Graph = vector<vector<bool>>;

bool GoodPath(const vector<int> &path, const Graph &g)
{
    for (size_t i = 1; i < path.size(); i += 1) {
        auto prev = path[i - 1];
        auto curr = path[i];

        if (!g[prev][curr]) {
            return false;
        }
    }
    return true;
}

int Back(vector<int> &st, vector<bool> &used, int level, const Graph &g)
{
    if (level >= (int)g.size()) {
        return GoodPath(st, g) ? 1 : 0;
    }

    auto total = 0;
    for (size_t i = 0; i < g.size(); i += 1) {
        if (used[i]) {
            continue;
        }

        st[level] = i;
        used[i] = true;

        total += Back(st, used, level + 1, g);
        used[i] = false;
    }
    return total;
}

int CountPaths(const Graph &g)
{
    vector<int> st(g.size());
    vector<bool> used(g.size(), false);

    st[0] = 0;
    used[0] = true;

    return Back(st, used, 1, g);
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    Graph graph(nodes, vector<bool>(nodes, false));
    for (auto i = 0; i < edges; i += 1) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }

    auto res = CountPaths(graph);
    cout << res << "\n";

    return 0;
}
