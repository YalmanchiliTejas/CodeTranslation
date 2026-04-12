// AtCoder template
// 見た奴全員saba!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

vector<vector<int>> graph(8);
int ans = 0;
bool visited[8];
int n;
int dfs(int now, int depth){
    visited[now] = true;
    if(depth == n) return 1;
    int ret = 0;
    rep(i,graph[now].size()){
        int next = graph[now][i];
        if(visited[next] || next == 0) continue;
        ret += dfs(next, depth+1);
        visited[next] = false;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m; cin >> n >> m;
    
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    
    rep(i,n) visited[i] = false;
    ans += dfs(0,1);
    
    cout << ans << endl;
}