#include <cstdio>
#define MAXN 9
int n, m, cnt;
bool graph[MAXN][MAXN];
bool vst[MAXN];

void dfs(int v, int num) {
    if(num == n) {
        cnt++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(graph[v][i] && !vst[i]) {
            vst[i] = true;
            dfs(i, num+1);
            vst[i] = false;
        }
    }
}

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    for(int i =1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        graph[a][b] = true;
        graph[b][a] = true;
    }
    vst[1] = true;
    dfs(1, 1);

    printf("%d\n", cnt);
    return 0;
}
