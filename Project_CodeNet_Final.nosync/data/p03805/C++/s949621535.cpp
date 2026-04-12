#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
int N,M;

int dfs(const Graph &G,int v,vector<bool> visited){

    bool all_visited = true;
    for(auto x: visited){
        if(!x) all_visited = false;
    }
    if(all_visited){
        return 1;
    }
    int ret = 0;
    for(auto nt :G.at(v)){
        if(visited.at(nt)) continue;
        visited.at(nt) = true;
        ret += dfs(G,nt,visited);
        visited.at(nt) = false;
    }
    return ret;
}
int main(){

    cin >> N >> M;
    Graph G(N);
    vector<bool> visited(N);
    for(int i = 0;i < M;i++){
        int a,b;
        cin >> a >> b;
        G.at(a-1).push_back(b-1);
        G.at(b-1).push_back(a-1);
    }

    for(int i = 0; i < N ;i++){
        visited.at(i) = false;
    }

    visited.at(0) = true;
    cout << dfs(G,0,visited) << endl;
}
