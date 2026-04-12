#include <stdio.h>

#define N 8

int dfs(int n, int adj[N][N], int vis[N], int pos){
    int allVis = 1, endNode = 1;
    int pathNum;
    
    for (int i=0; i<n; i++){
        if (i == pos) continue;
        if (vis[i] == 0) allVis = 0;
        if (vis[i] == 0 && adj[i][pos]) endNode = 0;
    }
    if (endNode){
        return allVis;
    }
    // まだ行けるところがある
    pathNum = 0;
    for (int i=0; i<n; i++){
        if (adj[i][pos] == 1 && vis[i] == 0){
            vis[i] = 1;
            pathNum += dfs(n, adj, vis, i);
            vis[i] = 0;
        }
    }
    return pathNum;
}

int main(void){
    int adj[N][N] = {0};
    int n, m;
    int vis[N] = {0};
    
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
        int s,d;
        scanf("%d %d", &s, &d);
        adj[s-1][d-1] = adj[d-1][s-1] = 1;
    }
    vis[0] = 1;
    printf("%d\n", dfs(n, adj, vis, 0));
    
    return 0;
}