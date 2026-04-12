#include <iostream>
#include <queue>
using namespace std;

const int nmax = 8;
int N, M;
bool pass[nmax][nmax] = {0};

int dfs(int v, bool visited[nmax]) {
    bool all_visited=true;
    for(int i=0; i<N; i++) if(visited[i]==false) all_visited=false;
    if(all_visited) return 1;


    int ret = 0;
    for(int i=0; i<N; i++) {
        if(!pass[v][i]) continue;
        if(visited[i]) continue;
        visited[i]=true;
        ret += dfs(i, visited);
        visited[i]=false;
    }
    return ret;
}

int main() {
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        pass[a-1][b-1]=pass[b-1][a-1]=true;
    }

    bool visited[nmax];
    for(int i=0; i<N; i++) visited[i]=false;
    visited[0]=true;
    cout << dfs(0, visited) << endl;
    return 0;
}
