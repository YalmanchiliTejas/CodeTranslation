#include <bits/stdc++.h>
using namespace std;
using Graph = vector< vector<int> >;
vector<bool> seen;
int ans;

void dfs(const Graph G,int v){
    seen[v] = true;
    bool check = true;
    for(int i=0;i<G.size();++i){
        if(!seen[i]){
            check = false;
            break;
        }
    }
    if(check) ans++;
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G,next_v);
    }
    seen[v] = false;
    
}

int main(){
    int n,m;
    cin >> n >> m;
    Graph G(n);
    for(int i=0;i<m;++i){
        int a,b; cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.assign(n,false);//全頂点を未訪問に初期化 特定の値で初期化したいとき、assign(n,val)
    dfs(G,0);
    cout << ans << endl;
    return 0;
}