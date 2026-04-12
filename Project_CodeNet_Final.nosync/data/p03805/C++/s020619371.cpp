#include<bits/stdc++.h>
using namespace std;

int answer = 0, n, m;
vector<int> adj[10];
bool processed[10]={false};
void dfs(int v){
    processed[v]=true;
    for(auto vert: adj[v]){
        if(processed[vert]==true) continue;
        dfs(vert);
        bool ok=true;
        for(int i=1; i<=n; i++){
            if(processed[i]==false) ok=false;
        }
        if(ok==true) answer++;
        processed[vert]=false;
    }
}


int main(){
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout<<answer;

    return 0;
}