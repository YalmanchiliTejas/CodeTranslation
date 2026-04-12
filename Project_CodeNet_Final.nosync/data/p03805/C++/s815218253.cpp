#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> g(10);
vector<bool> visited(10,false);
int ans = 0;
void dfs(int x, int depth, int n){
    if(depth == n) {
        ans++;
        return;
    }
    visited[x] = true;
    for(int nv:g[x]){
        if(visited[nv]) continue;
        dfs(nv,depth+1,n);
        visited[nv] = false;
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--; 
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,1,n);
    cout << ans << endl;
    return 0;
}