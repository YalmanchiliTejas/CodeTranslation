#include <bits/stdc++.h>
using namespace std;

// グローバルにしておく
int N, M;
vector<int> visited;
vector<vector<int>> G;
int num_visited = 0;
int ans = 0;

void dfs(int now){
    visited[now] = 1;
    num_visited++;
    // すべての頂点を訪れたなら
    if(num_visited == N){
        ans++;
    }
    for(int i=0; i<G[now].size(); i++){
        int next = G[now][i];
        if(!visited[next]) dfs(next);
    }
    visited[now] = 0;
    num_visited--;
}

int main() {
    cin >> N >> M;
    G = vector<vector<int>>(N); // サイズを確保する
    visited = vector<int>(N, 0);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // 頂点番号を 0-indexed とする
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 頂点番号 0 からDFSを始める
    dfs(0);
    cout << ans << endl;
}