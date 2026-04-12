/**
 *      purpose : 
 *      author  : kyomukyomupurin
 *      created : 
**/

#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define print(x) cout << (x) << '\n'

const int n_max = 8;
bool graph[n_max][n_max];

int dfs(int v, int n, bool visited[n_max]){
    bool all_visited = true;
    
    if (any_of(visited, visited + n, [](int x){return x == false;})) all_visited = false;
    if (all_visited) return 1;

    int cnt = 0;

    rep(i, n){
        if (!graph[v][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        cnt += dfs(i, n, visited);
        visited[i] = false;
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    int a[m], b[m];
    rep(i, m) {
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    bool visited[n_max] = {};

    visited[0] = true;
    print(dfs(0, n, visited));
    
    return 0;
}