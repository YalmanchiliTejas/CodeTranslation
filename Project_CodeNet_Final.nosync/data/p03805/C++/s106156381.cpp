#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define INF  numeric_limits<int>::max()
#define NINF numeric_limits<int>::min()

using namespace std;
using ll = long long;

using Edge = struct {
    bool is_valid = false;
    int  weight   = 0;
};

int graph_dfs(int                         vertex,
              const vector<vector<Edge>>& edge,
              vector<bool>&               reached_vertex) {
    if(accumulate(reached_vertex.begin(), reached_vertex.end(), 0) == (int)reached_vertex.size()) {
        return 1;
    }

    int ret = 0;
    REP(i, reached_vertex.size()) {
        if(reached_vertex[i] || !edge[vertex][i].is_valid) {
            continue;
        }

        reached_vertex[i] = true;
        ret += graph_dfs(i, edge, reached_vertex);
        reached_vertex[i] = false;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    vector<vector<Edge>> edge(N, vector<Edge>(N, Edge()));
    vector<bool> reached_vertex(N, false);

    REP(i, M) {
        int a, b;
        std::cin >> a >> b;
        edge[a - 1][b - 1] = edge[b - 1][a - 1] = Edge{true, 1};
    }

    reached_vertex[0] = true;
    std::cout << graph_dfs(0, edge, reached_vertex) << std::endl;

    return 0;
}
