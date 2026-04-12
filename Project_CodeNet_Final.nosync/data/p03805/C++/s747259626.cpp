#include <iostream>
using namespace std;

int n, m;
int G[10][10];
int ans;
bool used[10];

void dfs(int v, int cnt) {
    if (cnt == n) {
        ans++;
        return;
    }
    used[v] = true;
    for (int i = 0; i < n; i++) {
        if (!used[i] && G[v][i])
            dfs(i, cnt + 1);
    }
    used[v] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = G[b][a] = 1;
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}