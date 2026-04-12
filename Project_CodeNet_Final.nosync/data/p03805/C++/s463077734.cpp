#include <bits/stdc++.h>
using namespace std;

// 1を始点としてDFSでグラフ上を探索し条件を満たすパスを数え上げる

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int N, bool has_visited[nmax]) {
    bool has_visited_all = true;
    for (int i = 0; i < N; i++) {
        if (has_visited[i] == false) {
            has_visited_all = false;
        }
    }
    if (has_visited_all) {
        return 1;
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (graph[v][i] == false) {
            continue; // 辺が生えてないのでスルー
        }
        if (has_visited[i]) {
            continue; // すでに訪問済みなのでスルー
        }
        has_visited[i] = true;
        ret += dfs(i, N, has_visited);
        has_visited[i] = false;
    }
    return ret;
}

int main() {
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        graph[A-1][B-1] = graph[B-1][A-1] = true;
    }
    bool has_visited[nmax];
    for (int i = 0; i < N; i++) {
        has_visited[i] = false;
    }
    has_visited[0] = true;
    cout << dfs(0, N, has_visited) << endl;
    return 0;
}
