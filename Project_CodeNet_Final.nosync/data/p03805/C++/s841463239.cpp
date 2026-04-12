#include <iostream>
#include <vector>

using namespace std;

// n: 頂点数, m: 辺の数
int n, m;

int ans;
bool visited[8];
bool all_visited;

// max_n: 最大の頂点数
const int max_n = 8;
// 隣接リストによるグラフの表現
vector<int> G[max_n];

// cur: 現在 (current) いる頂点
void dfs(int cur) {
    visited[cur] = true;
    // cout << cur+1 << endl;
    all_visited = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) { ans++; }
    for (auto e: G[cur]) {
        if (!visited[e]) {
            dfs(e);
            visited[e] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        // 0-based index にしたいのでデクリメント
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}