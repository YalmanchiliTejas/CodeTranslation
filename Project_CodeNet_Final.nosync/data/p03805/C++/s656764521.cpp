#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using P =  pair<int, int>;
using T = tuple<int, int ,int>;
const int INF = 1e9;
const int MAX = 10;

// vector<vector<char>> field(MAX, vector<char>(MAX));    
vector<vector<bool>> graph(MAX, vector<bool>(MAX, false));
// vector<bool> visited(MAX, false);

int n,m;

int dfs(int v, int n, vector<bool> &visited){
    bool all_visited = true;
    rep(i,n) if(visited[i] == false) all_visited = false; 
    if(all_visited) return 1;  //全ての点にたどり着いていたらプラス1して返す

    int ret = 0;
    rep(i,n){
        if(graph[v][i] == false) continue;  //行き場がない
        if(visited[i]) continue;    //すでに着いた
        visited[i] = true;
        ret += dfs(i, n, visited); 
        visited[i] = false;     //前回の操作で全ての点にたどり着いたあと、起点を未到達にする
    }
    return ret;
}

int main(){
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = graph[b-1][a-1] = true;
    }
    vector<bool> visited(MAX, false);
    visited[0] = true;
    cout << dfs(0,n , visited) << endl;
    return 0;
}