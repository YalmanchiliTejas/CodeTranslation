#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nmax = 8;
bool graph[nmax][nmax];

//vは現在の頂点 
int dfs(int v, int n, bool visited[nmax]){
    
    bool all_visited = true;
    
    for (int i = 0; i < n; i++){
        if (visited[i] == false) all_visited = false;
    }
    
    
    if(all_visited) return 1;
    
    int ret = 0;
    
    for (int i = 0; i < n; i++){
        if (graph[v][i] == false) continue; //道がない
        if (visited[i]) continue; //すでに一度以上訪問した頂点であった
        
        visited[i] = true;
        ret += dfs(i, n, visited);
        visited[i] = false;
    }
    
    return ret;
}
int main(void){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        //隣接リストを作る
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
    
    bool visited[nmax];
    
    for (int i = 0; i < n; i++){
        visited[i] = false; //すべての頂点を未訪問にする
    }
    
    visited[0] = true; //頂点１よりスタートする
    cout << dfs(0, n, visited) << endl;
    return 0;
}
