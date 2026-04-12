#include <bits/stdc++.h>

#define mod 1000000007

#define rep(i, n) for(int i=0; i<n; ++i)

using namespace std;
typedef long long ll; 

bool graph[10][10];
int N, M;

int dfs(int v, bool visited[10]){
    bool all_visited = true;

    rep(i, N){
        if(visited[i] == false){
            all_visited = false;
            break;
        }
    }

    if(all_visited)
        return 1;

    int ret = 0;

    rep(i, N){
        if(graph[v][i] == false || visited[i])
            continue;
        visited[i] = true;
        ret += dfs(i, visited);
        visited[i] = false;
    }
    return ret;    
}

int main(void){
    cin >> N >> M;

    rep(i, N){
        rep(j, N){
            graph[i][j] = false;
        }
    }

    rep(i, M){
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }

    bool visited[10];
    
    rep(i, N)
        visited[i] = false;

    visited[0] = true;
    cout << dfs(0, visited) << endl;
}