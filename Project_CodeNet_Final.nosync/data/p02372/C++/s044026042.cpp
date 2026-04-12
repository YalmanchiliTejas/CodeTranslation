#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

template <class T>
struct Edge {
    int from, to;
    T cost;
    Edge(int from = -1, int to = -1, T cost = 1) : from(from), to(to), cost(cost){};

    bool operator<(const Edge<T>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<T>& e) const { return this->cost > e.cost; }
};

template <class T = int>
class Graph {
public:
    explicit Graph(int N = 0) : size(N) { path.resize(size); }
    void span(int u, int v, T cost = 1) { path[u].push_back(Edge<T>(u, v, cost)); }
    std::vector<Edge<T>> operator[](int v) const { return path[v]; }

    int size;
    std::vector<std::vector<Edge<T>>> path;
};

template <class Weight, class Data>
class ReRooting {
    using DataMerger = std::function<Data(Data, Data)>;
    using Promoter = std::function<Data(Data, Edge<Weight>)>;

public:
    Graph<Weight> tree;
    std::vector<Data> data;
    Data id;
    DataMerger merge;
    Promoter promote;

    ReRooting(const Graph<Weight>& tree, Data id, DataMerger merge, Promoter promote)
        : tree(tree), data(tree.size), id(id), merge(merge), promote(promote) {
        dfs(0);
        edfs(0);
    }

    // vを根とする部分木の解でdataを埋める
    Data dfs(int v, int r = -1) {
        data[v] = id;
        for (const auto& e : tree[v]) {
            if (e.to == r) continue;
            data[v] = merge(data[v], promote(dfs(e.to, v), e));
        }
        return data[v];
    }

    // vを根とする木の解を求める
    void edfs(int v, int r = -1, Data par_data = 0) {
        int cnum = tree[v].size();  // vから伸びる辺の数

        std::vector<std::pair<Data, int>> child;
        child.emplace_back(0, 0);  // index合わせ
        for (const auto& e : tree[v]) {
            if (e.to == r) {
                child.emplace_back(promote(par_data, e), e.to);
            } else {
                child.emplace_back(promote(data[e.to], e), e.to);
            }
        }

        std::vector<Data> lacc(cnum + 2), racc(cnum + 2);
        // 左から、右からの累積和
        lacc[0] = 0;
        for (int i = 1; i <= cnum; ++i) {
            lacc[i] = merge(lacc[i - 1], child[i].first);
        }
        racc[child.size()] = 0;
        for (int i = cnum; i >= 1; --i) {
            racc[i] = merge(racc[i + 1], child[i].first);
        }

        data[v] = lacc[cnum];  // 全体の累積和が答え

        for (int i = 1; i <= cnum; ++i) {
            if (child[i].second == r) continue;
            edfs(child[i].second, v, merge(lacc[i - 1], racc[i + 1]));
        }
    }
};

int main() {
    int N;
    std::cin >> N;
    Graph<int> tree(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        tree.span(u, v, w);
        tree.span(v, u, w);
    }

    // Data    : 最も遠い頂点までの距離
    // Merger  : max (id = 0)
    // Promoter: + cost
    ReRooting<int, int> dp(tree, 0,
                           [](int a, int b) { return std::max(a, b); },
                           [](int a, const Edge<int>& e) { return a + e.cost; });
    for (auto d : dp.data) {
        std::cout << d << std::endl;
    }
    return 0;
}

