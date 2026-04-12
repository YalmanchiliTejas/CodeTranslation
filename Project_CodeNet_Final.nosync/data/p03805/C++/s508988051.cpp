#include <iostream>
using namespace std;

bool g[8][8];
int N, M;
int dfs(int v, int n, bool visited[]){
    bool all = true;
    for(int i=0;i<N;i++){
        if(visited[i] == false) all=false;
    }
    if(all) return 1;
    int ret=0;
    for(int i=0;i<N;i++){
        if(g[v][i]==false) continue;
        if(visited[i]) continue;

        visited[i]=true;
        ret+=dfs(i, n, visited);
        visited[i]=false;
    }
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) g[i][j] = false;
    }
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        g[a-1][b-1] = true;
        g[b-1][a-1] = true;
    }
    bool visited[N];
    for(int i=0;i<N;i++) visited[i] = false;
    visited[0] = true;
    int ans = dfs(0, 0, visited);
    cout << ans << endl;
}