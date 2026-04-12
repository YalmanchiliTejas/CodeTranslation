#include <iostream>

using namespace std;

const int n_max = 8;
int N, M;
int Graph[n_max][n_max];
bool is_visited[n_max];

int dfs(int cur_v) {
    bool all_visited = true;
    for (int i = 0; i < N; i++) {
        if (is_visited[i] == false) {
            all_visited = false;
            break;
        }
    }
    if (all_visited) { return 1; }
    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (Graph[cur_v][i] == 0) { continue; }
        if (is_visited[i]) { continue; }

        is_visited[i] = true;
        ret += dfs(i);
        is_visited[i] = false;
    }
    return ret;
}

int main() {
    int a, b;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Graph[a-1][b-1] = Graph[b-1][a-1] = 1;
    }
    for (int i = 0; i < N; i++) {
        is_visited[i] = false;
    }
    is_visited[0] = true;

    cout << dfs(0) << endl;

    return 0;
}
