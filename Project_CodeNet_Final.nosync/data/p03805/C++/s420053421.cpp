//
//  lib.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template <typename T>
vector<vector<T>> alloc_double_vec(size_t rows, size_t cols, T init) {
    vector<vector<T>> ret;
    vector<T> ret_elem;
    ret_elem.resize(cols, init);
    ret.resize(rows, ret_elem);
    return ret;
}

struct Graph {
    struct Edge {
        size_t from;
        size_t to;
    };
    vector<vector<Edge>> edges;
    Graph(size_t size) {
        edges.resize(size);
    }
    void add_edge(size_t from, size_t to) {
        edges[from].push_back(Edge{from, to});
        edges[to].push_back(Edge{to, from});
    }
};

void dfs(const Graph& graph, size_t now, vector<bool>& used, int& answer) {
    used[now] = true;
    bool some_false = false;
    for (int i = 0; i < used.size(); i++) {
        if (!used[i]) {
            some_false = true;
            break;
        }
    }
    if (some_false) {
        for (Graph::Edge e : graph.edges[now]) {
            if (used[e.to]) {
                continue;
            }
            dfs(graph, e.to, used, answer);
        }
    } else {
        answer++;
    }
    used[now] = false;
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.add_edge(a, b);
    }
    vector<bool> used(N, false);
    int answer = 0;
    dfs(graph, 0, used, answer);
    cout << answer << endl;
}
