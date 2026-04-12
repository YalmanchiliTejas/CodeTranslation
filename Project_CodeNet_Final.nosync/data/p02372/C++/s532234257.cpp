#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=10005;

struct edge {
    int to,cost;
};

int n,h[maxn],hs[maxn],tag[maxn];
vector<edge>G[maxn];

void dfs1(int u,int p) {
    for (edge e:G[u]) {
        if (e.to==p) continue;
        dfs1(e.to,u);
        if (h[u]<h[e.to]+e.cost) {
            hs[u]=h[u];
            h[u]=h[e.to]+e.cost;
        }
        else hs[u]=max(hs[u],h[e.to]+e.cost);
    }
}

void dfs2(int u,int p) {
    for (edge e:G[u]) {
        if (e.to==p) continue;
        if (tag[u] && h[u]==h[e.to]+e.cost)
            tag[e.to]=1,
            h[e.to]=max(h[e.to],hs[u]+e.cost);
        else h[e.to]=max(h[e.to],h[u]+e.cost);
        hs[e.to]=max(hs[e.to],hs[u]+e.cost);
        dfs2(e.to,u);
    }
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for (int i=0;i<n-1;i++) {
        int u,v,w; cin>>u>>v>>w;
        G[u].pb((edge){v,w});
        G[v].pb((edge){u,w});
    }
    dfs1(0,-1);
    tag[0]=1;
    dfs2(0,-1);
    for (int i=0;i<=n-1;i++) cout<<h[i]<<'\n';
}
