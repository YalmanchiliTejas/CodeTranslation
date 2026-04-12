#include<bits/stdc++.h>

using namespace std;

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v,int N,bool visited[nmax]){
    bool all_visited = true;

    for(int i = 0;i < N;i++){
        if(!visited[i]){
            all_visited = false;
        }
    }

    if(all_visited){
        return 1;
    }

    int ret = 0;
    for(int i = 0;i < nmax;i++){
        if(!graph[v][i]){
            continue;
        }
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        ret += dfs(i,N,visited);
        visited[i] = false;
    }
    return ret;
}

int main(){
    int N,M,a,b,ans;
    bool visited[nmax];
    
    cin >> N >> M;
    for(int i = 0;i < nmax;i++){
        visited[i] = false;
        for(int j = 0;j < nmax;j++){
            graph[i][j] = false;
        }
    }

    for(int i = 0;i < M;i++){
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }
    visited[0] = true;
    ans = dfs(0,N,visited);

    cout << ans << endl;
    return 0;
}