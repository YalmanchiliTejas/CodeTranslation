#include <bits/stdc++.h>
using namespace std;

const int N = 19;

int n, m;
long long ans = 0;
bool b[N]={};
vector<int> adj[N];

void dfs(int u, int cnt){
    if(cnt == n){
        ans++;
        return;
    }

    b[u] = true;
    for(int v : adj[u]){
        if(!b[v]){
            dfs(v, cnt+1);
        }
    }
    b[u] = false;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++){
        int x, y; scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,1);

    printf("%lld\n", ans);
    return 0;
}
