#include <bits/stdc++.h>
#define rep(i ,n) for(int i = 0; i < (n); i++)
#define ll long long
using namespace std;

int nmax = 8;
vector<vector<bool>> graph(nmax, vector<bool>(nmax, false));

int dfs(int c, int N, vector<bool> visited){
    bool all_visited = true;
    rep(i, N){
        if(!visited[i]){
            all_visited = false;
        }
    }
    if(all_visited){
        return 1;
    }
    int count = 0;
    rep(i, N){
        if(!graph[c][i] || visited[i]){
            continue;
        }
        visited[i] = true;
        count += dfs(i, N, visited);
        visited[i] = false;
    }
    return count;
}

int main(){
    int N, M; cin >> N >> M;
    vector<bool> visited(N, false);
    rep(i, M){
        int a, b; cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }
    visited[0] = true;
    int ans = dfs(0, N, visited);
    cout << ans << endl;
    return 0;
}