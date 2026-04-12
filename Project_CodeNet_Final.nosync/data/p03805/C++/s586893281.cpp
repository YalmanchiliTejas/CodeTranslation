#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 10;
bool graph[MAX][MAX];
bool visited[MAX];

int N;

int dfs(int v){
    int ret = 0;
    visited[v] = true;

    bool all_visited = true;
    for(int i=1; i<=N; i++) if(visited[i] == false) all_visited = false;
    if(all_visited){
        visited[v] = false;
        return 1;
    } 

    for(int v2=1; v2<=N; v2++){
        if(graph[v][v2] == true && visited[v2] == false){
            ret += dfs(v2);
        }
    }

    visited[v] = false;
    return ret;
}

int main(void){
    int M; cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        graph[a][b] = graph[b][a] = true;
    }

    for(int i=1; i<=N; i++) visited[i] = false;

    cout << dfs(1) << endl;
}