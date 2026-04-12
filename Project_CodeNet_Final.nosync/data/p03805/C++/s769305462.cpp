#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define INF  numeric_limits<int>::max()
#define NINF numeric_limits<int>::min()

using namespace std;
using ll = long long;

const int N_MAX = 8;
int N, M;
bool edge[N_MAX][N_MAX];
bool reached_vertex[N_MAX];

int dfs(int vertex) {
    if(std::accumulate(reached_vertex, reached_vertex + N, 0) == N) {
        return 1;
    }

    int ret = 0;
    REP(i, N) {
        if(!edge[vertex][i] || reached_vertex[i]) continue;

        reached_vertex[i] = true;
        ret += dfs(i);
        reached_vertex[i] = false;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    std::cin >> N >> M;
    REP(i, N) {
        reached_vertex[i] = 0;
    }

    REP(i, M) {
        int a, b;
        std::cin >> a >> b;
        edge[a - 1][b - 1] = edge[b - 1][a - 1] = true;
    }

    reached_vertex[0] = true;
    std::cout << dfs(0) << std::endl;

    return 0;
}
