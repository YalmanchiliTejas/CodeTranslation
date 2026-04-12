#include<iostream>
#include<vector>

using namespace std;

int N,M;
vector<vector<int>> adj;
vector<vector<int>> orders;
vector<int> nt;

int next(int u){
    for(int v=nt[u]+1; v<N; v++){
        if(adj[u][v]==1){
            nt[u]=v;
            return v;
        }
    }
    return -1;
}

int dfs(int u,vector<bool> visited){
    bool all_visited=true;

    visited[u]=true;
    
    for(int i=0; i<N; i++){
       if(visited[i]==false){
           all_visited=false;
           break;
       }
    }

    if(all_visited){
        //cout<<1<<endl;
        return 1;
    }

    int ret=0;
    for(int v=1; v<N; v++){
        if(visited[v]==true){
            //cout<<v+1<<"は探索済み"<<endl;
            continue;
        }
        if(adj[u][v]==0){
            //cout<<u+1<<" → "<<v+1<<"は存在しない"<<endl;
            continue;
        }
        visited[v]=true;
        ret+=dfs(v,visited);
        visited[v]=false;
    }
    //cout<<ret<<endl;
    return ret;
}

int main(){
    vector<bool> visited;
    cin>>N>>M;

    adj.resize(N);
    nt.resize(N,(-1));
    visited.resize(N);

    for(int i=0; i<N; i++){
        adj[i].resize(N,(0));
    }
/*
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<adj[i][j];
        }cout<<endl;
    }
*/
    for(int i=0; i<M; i++){
        int u,v;
        cin>>u>>v;
        adj[u-1][v-1]=1;
        adj[v-1][u-1]=1;
    }

    cout<<dfs(0,visited)<<endl;
    return 0;
}