#include <bits/stdc++.h>
using namespace std;

const int MAX=8;
int N;

bool graph[MAX][MAX];
bool visited[MAX];

int dfs(int v){
    visited[v]=true;
    
    bool all_visited=true;
    for(int i=0; i<N; i++) if(visited[i]==false) all_visited=false;

    if(all_visited){
        visited[v]=false;
        return 1;
    }

    int ret=0;

    for(int i=0; i<N; i++){
        if(graph[v][i]==false or visited[i]==true) continue;
        ret += dfs(i);
    }

    visited[v]=false;
    return ret;
}

int main(void){
    int M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b;
        a--; b--;
        graph[a][b]=graph[b][a]=true;
    }

    cout << dfs(0) << endl;

    return 0;
}