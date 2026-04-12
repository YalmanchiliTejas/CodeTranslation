#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

const int nmax = 8;
bool graph[nmax][nmax];

int dfs(int v, int n, bool visited[nmax]){
    bool all_visited = true;

    roop(i, n){
        if(visited[i] == false){
            all_visited = false;
        }
    }

    if(all_visited) return 1;

    int ret = 0;

    roop(i, n){
        if(graph[v][i] == false) continue;
        if(visited[i]) continue;

        visited[i] = true;
        ret += dfs(i,n,visited);
        visited[i] = false;
    }

    return ret;
}

int main(void){

    int n, m;
    cin >> n >> m;

    roop(i, m){
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }

    bool visited[nmax];
    roop(i, n){
        visited[i] = false;
    }

    visited[0] = true;
    cout << dfs(0, n, visited) << endl;

    return 0;
}