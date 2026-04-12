#include <bits/stdc++.h>
#define N 100034
#define M 256101

int n, e;
int u, v, i;
int to[M], first[N], next[M];

inline void addedge(int u, int v){
    to[++e] = v; next[e] = first[u]; first[u] = e;
    to[++e] = u; next[e] = first[v]; first[v] = e;
}

int dfs(int x, int px){
    int i, y, scx = 0;
    for(i = first[x]; i; i = next[i])
        if((y = to[i]) != px)
            if((scx += dfs(y, x)) >= 2)
                return 2;
    return !scx;
}

int main(){
    scanf("%d", &n);
    for(i = 1; i < n; ++i){
        scanf("%d%d", &u, &v);
        addedge(u, v);
    }
    puts(dfs(1, 0) ? "First" : "Second");
    return 0;
}