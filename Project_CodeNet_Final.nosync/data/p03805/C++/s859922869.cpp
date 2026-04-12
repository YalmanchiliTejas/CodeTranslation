#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
bool visited[10];  // 既に見たことがある頂点か記録
bool flag; //判別

int dfs(const Graph &G, int v, int N,bool visited[10]){

    flag = true;
    for (int i = 1; i <= N; i++) {
        if(visited[i] == false) flag = false;
    }
    if(flag) return 1;

    int sum = 0;
    for (auto next : G[v]){
        if(visited[next]) continue; // 訪問済みでなければ探索
        visited[next] = true;
        sum += dfs(G, next, N, visited);
        visited[next] = false;
    }

    return sum;
}
 
int main() {
    int N, M;
    cin >> N >> M;
    int a, b;
    Graph G(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    visited[1] = true;
    ans = dfs(G, 1, N,visited);
    cout << ans << endl;
    return 0;
}