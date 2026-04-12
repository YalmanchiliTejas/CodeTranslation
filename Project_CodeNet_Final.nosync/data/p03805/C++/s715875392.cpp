#include <iostream>
#include <vector>
using namespace std;

using Graph=vector<vector<int>>;

int ans;int N,M;

void dfs(Graph &G,bool *seen,int v){
    
    bool ok=true;
    for(int i=1;i<N+1;i++){if((!seen[i])&&(i!=v)){ok=false;}}
    if(ok){ans++;return;}
    seen[v]=true;
    for(auto next_v:G[v]){
        if(seen[next_v]){continue;}
        dfs(G,seen,next_v);
    }

    seen[v]=false;

}

int main(){
    ans=0;
    cin >> N>>M;
    Graph G(N+1);
    G.assign(N+1,vector<int>());
    bool seen[N+1]={};
    for(int i=0;i<M;i++){
        int a,b;
        cin >>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(G,seen,1);
    cout << ans<<endl;
    return 0;
}