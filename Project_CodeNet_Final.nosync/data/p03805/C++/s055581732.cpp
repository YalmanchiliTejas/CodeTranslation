#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int nmax = 8;
vector<vector<bool>> graph(nmax, vector<bool>(nmax, false));
vector<bool> visited(nmax, false);

int dfs(int v, int n, vector<bool> & visited){
    
    bool all_visited = true;
    
    for (int i = 0; i < n; i++){
        if(!visited[i]) all_visited = false;
    }
    
    if(all_visited) return 1;
    
    int res = 0;
    
    for (int i = 0; i < n; i++){
        if(!graph[v][i]) continue;
        if(visited[i]) continue;
        
        visited[i] = true;
        res += dfs(i, n, visited);
        visited[i] = false;
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    visited[0] = true;
    cout << dfs(0, n, visited) << endl;
}