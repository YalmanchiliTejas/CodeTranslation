#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int N = 100;
constexpr int INF = 1 << 30;

void solve() {
    int a, b;
    std::cin >> a >> b;

    auto ds = vec(a + 1, vec(b + 1, 0));
    for (int x = 1; x <= a; ++x) {
        for (int y = 1; y <= b; ++y) {
            std::cin >> ds[x][y];
        }
    }

    auto graph = vec(N + 1, vec(N + 1, 0));
    for (int x = 1; x <= a; ++x) {
        for (int y = 1; y <= b; ++y) {
            auto d = ds[x][y];

            for (int i = 0; i <= N; ++i) {
                for (int j = 0; j <= N; ++j) {
                    graph[i][j] = std::max(graph[i][j], d - x * i - y * j);
                }
            }
        }
    }

    for (int x = 1; x <= a; ++x) {
        for (int y = 1; y <= b; ++y) {
            int dmin = INF;
            for (int i = 0; i <= N; ++i) {
                for (int j = 0; j <= N; ++j) {
                    dmin = std::min(dmin, graph[i][j] + x * i + y * j);
                }
            }

            if (dmin != ds[x][y]) {
                std::cout << "Impossible" << std::endl;
                return;
            }
        }
    }

    std::cout << "Possible" << std::endl;

    std::cout << (N + 1) * 2 << " " << N * 2 + (N + 1) * (N + 1) << std::endl;
    for (int v = 1; v <= N; ++v) {
        std::cout << v << " " << v + 1 << " X" << std::endl;
    }
    for (int v = 1; v <= N; ++v) {
        std::cout << N + 1 + v + 1 << " " << N + 1 + v << " Y" << std::endl;
    }

    for (int u = 0; u <= N; ++u) {
        for (int v = 0; v <= N; ++v) {
            std::cout << u + 1 << " " << N + 1 + v + 1 << " "
                      << graph[u][v] << std::endl;
        }
    }

    std::cout << 1 << " " << N + 2 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
