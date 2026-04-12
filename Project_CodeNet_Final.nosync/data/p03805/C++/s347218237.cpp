#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <set>
#include <stack>
#include <deque>

#define INF 1000000000;
#define MOD 1000000007;
#define LIMIT 1000000000000000000;
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

vector<bool> g_visited;
vector<vector<bool>> g_graph;

int dfs(int now_node, int all_node_cnt, vector<bool> visited) {
    bool all_visited = true;
    for (int i = 0; i < all_node_cnt; i++) {
        if (!visited[i]) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) return 1;

    int ret = 0;
    for (int i = 0; i < all_node_cnt; i++) {
        if (g_graph[i][now_node] == false) continue;
        if (visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, all_node_cnt, visited);
        visited[i] = false;
    }
    return ret;
}

int main()
{
    int N, M; cin >> N >> M;
    g_graph.assign(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g_graph[a][b] = g_graph[b][a] = true;
    }
    g_visited.assign(N, false);

    g_visited[0] = true;
    int ans = dfs(0, N, g_visited);
    cout << ans << endl;
}