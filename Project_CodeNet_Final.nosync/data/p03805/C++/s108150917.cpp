#include <bits/stdc++.h>
using namespace std;

bool g[10][10];
bool color[10];
int n, m;

int dfs(int x) {
    bool judge = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) judge = false;
    }
    if (judge) {
        return 1;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (g[x][i] && !color[i]) {
            color[i] = true;
            res += dfs(i);
            color[i] = false;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;

    fill(color, color + n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }

    color[1] = true;
    cout << dfs(1) << endl;
}
