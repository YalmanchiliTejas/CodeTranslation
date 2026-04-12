#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nmax = 8;
vector<vector<bool>> graph(nmax, vector<bool>(nmax, false));

//nは超点数 vは現在の頂点番号
int dfs(int n, int v, vector<bool> & visited){
    bool all_visited = true;
    
    //すべての頂点を訪問しているかどうか調べる
    for (int i = 0; i < n; i++){
        if (!visited[i]) all_visited = false;
    }
    
    if (all_visited) return 1; //条件を満たすパスを一つ発見した
    
    int ret = 0;
    
    for (int i = 0; i < n; i++){
        
        //隣接していない場合はだめ
        //１度以上訪問している場合もダメ
        if (!graph[v][i]) continue;
        if (visited[i]) continue;
        
        visited[i] = true; //頂点vに隣接した頂点iを訪問する
        
        ret += dfs(n, i, visited);
        
        visited[i] = false; //iを未訪問に戻す
    }
    
    return ret;
    
}

int main(){
    int n, m;
    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        
        //隣接リストを作る
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    //訪問済みの頂点と未訪問の頂点を管理する
    vector<bool> visited(nmax, false);
    
    // 頂点０を始点とする
    visited[0] = true;
    
    //dfs -> 頂点０から出発して, n個の頂点すべてを一筆書きで訪問するパスの総数
    cout << dfs(n, 0, visited) << endl;
}