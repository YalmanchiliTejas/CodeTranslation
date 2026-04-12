#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
#define endl '\n'
using namespace std;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
typedef pair<ll, ll> P;
const int nmax = 8;
bool graph[nmax][nmax];

// visted:そのグラフに訪れたことがあるかどうか
int dfs(int v, int N, bool visited[nmax]) {
    bool all_visited = true;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            all_visited = false;
        }
    }
    // 全ての頂点を訪問済みならば答えを1増やす
    if (all_visited) {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        // 頂点i:頂点vに隣接しているかつ未訪問
        if (graph[v][i] == false || visited[i]) {
            continue;
        }
        // 頂点iを訪問済みにする
        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
    }

    bool visited[nmax];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    cout << dfs(0, n, visited) << endl;
    return 0;
}