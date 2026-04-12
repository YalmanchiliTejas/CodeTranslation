#include <bits/stdc++.h>
using namespace std;
bitset<8> adj[8];
int n,m;
int ct=0,z=0;

void dfs(int x, int p) {
    //printf("%d %d\n", x, p);
    if (x==(1<<n)-1) {
        ct++;
        return;
    }
    for (int i=0; i<n; i++) {
        //printf("%d %d %d %d\n", x, p, i, adj[p][i] ? 1 : 0);
        if (!(1<<i & x) && adj[p][i]) {
            dfs(x+(1<<i),i);
        }
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a--; b--;
        adj[a][b]=true;
        adj[b][a]=true;
    }
    dfs(1,0);
    printf("%d\n", ct);
}