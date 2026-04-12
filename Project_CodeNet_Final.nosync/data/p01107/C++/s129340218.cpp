#include <iostream>
#include <vector>
#include <string>
#include <queue>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

const std::vector<int>
    dx{-1, 0, 1, 0},
    dy{0, -1, 0, 1};

bool solve() {
    int n, m;
    std::cin >> n >> m;
    if (n == 0) return false;

    int nn = n * m;
    auto enc = [&](int x, int y) { return x * m + y; };

    std::vector<std::string> ss(n);
    for (auto& s : ss) std::cin >> s;

    Graph<bool> graph(nn);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (ss[x][y] == '#') continue;

            int v = enc(x, y);

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i],
                    ny = y + dy[i];

                if (nx < 0 || n <= nx ||
                    ny < 0 || m <= ny ||
                    ss[nx][ny] == '#') continue;

                int u = enc(nx, ny);
                graph[v].emplace_back(v, u, true);
            }
        }
    }

    std::vector<bool> ok(nn, true);
    auto reachable =
        [&](int s, int t) -> bool {
        std::vector<bool> visited(nn, false);
        std::queue<int> que;

        visited[s] = true;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (auto e : graph[v]) {
                int u = e.dst;
                if (visited[u] || !ok[u]) continue;

                visited[u] = true;
                que.push(u);
            }
        }

        return visited[t];
    };

    for (int r = 0; r < nn; ++r) {
        if (r == enc(0, 0) || r == enc(n - 1, m - 1) ||
            r == enc(n - 1, 0) || r == enc(0, m - 1)) continue;

        ok[r] = false;

        if (!reachable(enc(0, 0), enc(n - 1, m - 1)) ||
            !reachable(enc(n - 1, 0), enc(0, m - 1))) {
            std::cout << "NO" << std::endl;
            return true;
        }

        ok[r] = true;
    }

    std::cout << "YES" << std::endl;
    return true;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    while (solve()) {}

    return 0;
}

