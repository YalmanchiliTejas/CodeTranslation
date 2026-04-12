#include <iostream>
#define MAX_N 8
#define MAX_M 28
using namespace std;
int N,M;

bool g[MAX_N][MAX_N] = {false};

int dfs(int v, int N, bool visited[MAX_N]){
    bool is_complete = true;
    for(int i = 0; i < N;i++){
        if(visited[i] == false) is_complete = false;
    }

    if(is_complete) return 1;
    int ret = 0;

    for(int i = 0; i < N; i++){
        if(g[v][i] == false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i,N,visited);
        visited[i] = false;
    }
    return ret;
}

int main(){
    cin >> N >> M;
    int f,t;
    for(int i = 0; i < M; i++){ 
        cin >> f >> t;
        g[f-1][t-1] = true;
        g[t-1][f-1] = true;
    }

    bool visited[MAX_N];
    for(int d = 0; d < N; d++) visited[d] = false;

    visited[0] = true;
    cout << dfs(0,N,visited) << endl;
    return 0;
}