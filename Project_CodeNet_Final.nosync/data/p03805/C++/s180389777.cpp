#include <bits/stdc++.h>
using namespace std;
const int nmax = 8;
bool graph[nmax][nmax];

// 再帰する際に持たせたいのはどこまで探索したか(visited)とどこに始点があるか
int dfs(int v, int N, bool visited[nmax]) {
    bool all_visited = true;

    // ここが頂点を探索したかどうかを毎回チェックするところ
    for(int i = 0; i < N; i++) {
        if(visited[i] == false) {
            all_visited = false;
        }
    }

    // 全部の探索に成功したらあとは順番に1を加算していくだけ、その最初の1をここで宣言していく
    if(all_visited) {
        return 1;
    }

    int ret = 0;

    for(int i = 0; i < N; ++i) {
        if(graph[v][i] == false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[A-1][B-1] = graph[B-1][A-1] = true;   // 隣接行列を作るとはこういうこと
    }

    bool visited[nmax];
    for(int i = 0; i < N; ++i) {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    return 0;
}