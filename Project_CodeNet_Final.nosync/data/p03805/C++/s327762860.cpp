#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int n, m;
int ans = 0;

struct Edge{
    /*辺の情報を入れる構造体で行き先とコストを表している*/
    int to;
    Edge(int to) : to(to) {}
};

vector<Edge> g[35];

void dfs(int u, vector<bool> used){
    //cout<<u<<endl;
    bool end = true;
    rep(i, n){
        if(!used[i] && i!=u) end = false;
    }
    if(end) ans++;
    else{
        for(auto p : g[u]){
            int v = p.to;
            if(!used[v]){
                vector<bool> tmp = used;
                tmp[u] = true;
                dfs(v, tmp);
            }
        }
    }
}
int main(void){
    cin>>n>>m;
    rep(i, m){
        int a, b;
        cin>>a>>b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool>used(n, false);
    dfs(0, used);
    cout<<ans<<endl;
    return 0;
}