//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long LL;

const int maxn = 1e5 + 5;
vector<int> g[maxn];

int dfs(int u,int fa) {
    int t = 0;
    int k[4];
    k[0] = k[1] = k[2] = k[3] = 0;
    for(auto v:g[u]) {
        if(v == fa) continue;
        t++;
        k[dfs(v,u)]++;
    }
    if(t == 0) return 1;
    if(k[3]) return 3;
    if(k[2] == t) return 1;
    if(k[1] > 1) return 3;
    if(k[1] == 1) return 2;
    return 0;
}

int main() {
    int n,i,u,v;
    scanf("%d",&n);
    for(i = 1; i < n; i++) {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i = 1; i <= min(n,100); i++) {
        u = dfs(i,0);
        if(u == 1 && g[i].size() == 1) u = 3;
        if(u == 3)
        {
            printf("First\n");
            return 0;
        }
    }
    printf("Second\n");
    return 0;
}
