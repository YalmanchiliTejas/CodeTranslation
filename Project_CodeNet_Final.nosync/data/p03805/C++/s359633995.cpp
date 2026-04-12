#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define print(x) cout << x << endl;
using namespace std;
typedef long long ll;

const int nmax = 8;
int graph[nmax][nmax];

int dfs(int v, int N, bool visited[]) {

    bool all_visited = true;

    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            all_visited = false;
        }
    }

    if (all_visited) {
        return 1;
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        if (graph[v][i] == false) continue;
        if (visited[i]) continue;

        visited[i] = true;
        ret += dfs(i, N, visited);
        visited[i] = false;
    }

    return ret;
}


int main() {
    int N, M;
    cin >> N >> M;
    int a, b;

    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, N, visited) << endl;
    
    return 0;
}