#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<bool>> linked_list;

int dfs(int v, int n, vector<bool> visited){
   bool all_visited = true;
   for(int i=0; i<n; ++i){
       if (visited[i] == false){
           all_visited = false;
       }
   } 
   if(all_visited) return 1;
   int res = 0;
   for(int i=0; i<n; ++i){
       if(linked_list[v][i]){
           if(visited[i]) continue;
           visited[i] = true;
           res += dfs(i, n, visited);
           visited[i] = false;
       }
   }
   return res;
}
signed main(){
    int n, m;
    cin >> n >> m;
    linked_list.resize(n);
    for(int i=0; i<n; ++i) linked_list[i].resize(n, false);
    for(int i=0; i<m; ++i){
        int start, end;
        cin >> start >> end;
        linked_list[start-1][end-1] = true;
        linked_list[end-1][start-1] = true;
    }
    vector<bool> visited(n, false);
    visited[0] = true;
    cout << dfs(0, n, visited) << endl;

    return 0;
}