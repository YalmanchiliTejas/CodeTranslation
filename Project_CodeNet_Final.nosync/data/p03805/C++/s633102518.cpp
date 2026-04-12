// AtCoder template
// 見た奴全員saba!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

vector<vector<int>> graph(8);

vector<bool> used(8,false);
int n;
int dfs(int now, int depth){
    if(used[now]) return 0;
    if(depth == n) return 1;
    int ret = 0;
    used[now] = true;
    rep(i,graph[now].size()) ret += dfs(graph[now][i], depth+1);    
    used[now] = false;
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // グラフ構築
    int m; cin >> n >> m;
    int a,b; rep(i,m){
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int ans = 0;
    ans += dfs(0, 1);
    cout << ans << "\n";
}