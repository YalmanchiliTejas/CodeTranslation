#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, a, b, ans;
int num[11];
bool edge[11][11], vis[11];

void dfs(int u, int rem) {
    if(rem == 0) {
        ++ans;
        return;
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i] && edge[u][i]) {
            vis[i] = true;
            dfs(i, rem - 1);
            vis[i] = false;
        }
    }
}

int main() {
    while(2 == scanf("%d%d", &n, &m)) {
        memset(num, 0, sizeof(num));
        memset(edge, false, sizeof(edge));
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            edge[a][b] = edge[b][a] = 1;
        }
        ans = 0;
        vis[1] = true;
        dfs(1, n - 1);
        printf("%d\n", ans);
    }
    return 0;
}
