#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define INF  numeric_limits<int>::max()
#define NINF numeric_limits<int>::min()

using namespace std;
using ll = long long;
using Edge = vector<vector<pair<int, int>>>; // src -> dst, weight

/**
 *  全ての頂点を通過するパスの数をDFSで求める
 *  @vertex       : 現在着目している頂点のindex
 *  @edge         : 辺の情報
 *  @vertex_label : 頂点の情報(到達済み : 1, 未到達 : 0)
 *  @Return       : 全ての頂点を通過するパスの数
 */
int graph_dfs(int          vertex,
              const Edge&  edge,
              vector<int>& vertex_label) {
    if(accumulate(vertex_label.begin(), vertex_label.end(), 0) == (int)vertex_label.size()) {
        return 1;
    }

    int ret = 0;
    REP(i, edge[vertex].size()) {
        int dst = edge[vertex][i].first;

        if(vertex_label[dst] == 0) {
            vertex_label[dst] = 1;
            ret += graph_dfs(dst, edge, vertex_label);
            vertex_label[dst] = 0;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    Edge        edge(N);
    vector<int> vertex_label(N, 0);

    REP(i, M) {
        int u, v;
        std::cin >> u >> v;

        // 重み無し無向グラフ
        edge[u - 1].emplace_back(v - 1, 0);
        edge[v - 1].emplace_back(u - 1, 0);
    }

    vertex_label[0] = 1;
    std::cout << graph_dfs(0, edge, vertex_label) << std::endl;

    return 0;
}
