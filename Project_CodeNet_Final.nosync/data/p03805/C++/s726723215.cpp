#include <iostream>
const int nmax = 8;
bool gragh[nmax][nmax];

using namespace std;

int dfs(int v, int N, bool visited[nmax]) {

    bool all_visited = true;

    for(int i = 0; i < N; ++i) {
        // 訪れていないところがあれば
        if (visited[i] == false) all_visited = false;
    }

    if (all_visited) return 1;

    int ret = 0;

    // すべての可能性を上げる
    for(int i = 0; i < N; ++i) {
        // 辺がなければ
        if (gragh[v][i] == false) continue;
        // すでに訪れていれば
        if(visited[i] == true) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);

        // 次のループのためにフラグを折る
        visited[i] = false;
    }

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    // 隣接行列を作る　
    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        gragh[a-1][b-1] = gragh[b-1][a-1] = true;
    }

    bool visited[nmax];
    for(int i = 0; i < N; ++i) {
        visited[i] = false;
    }
    // 1が始点
    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    return 0;
}