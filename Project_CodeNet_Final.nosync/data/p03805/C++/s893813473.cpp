#include <iostream>
using namespace std;
const int N_MAX = 8;
int N;
int M;
bool edge[N_MAX][N_MAX];
bool visited[N_MAX];
int ans = 0;
void dfs (int v) {
    bool end = true;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) end = false;
    }
    if (end) ans++;

    for (int i = 0; i < N; i++) {
        if (edge[v][i] && !visited[i]) {
            visited[i] = true;
            dfs(i);
            visited[i] = false;
        }
    }
}
int main (void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            edge[i][j] = false;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a][b] = true;
        edge[b][a] = true;
    }

    for (int i = 0; i < N; i++) visited[i] = false;
    visited[0] = true;
    dfs(0);

    cout << ans << endl;

    return 0;
}