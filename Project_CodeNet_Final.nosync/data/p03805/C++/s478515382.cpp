#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int n, m;
vector<int> to[8];
vector<bool> visited(8);
int cnt = 0;
void dfs(int cur, int dep) {
    //printf("%d %d\n", cur, dep);
    visited[cur] = true;
    if(dep == n-1) {
        cnt++;
        //return;
    }
    for(int v : to[cur]) {
        if(visited[v]) continue;
        dfs(v, dep+1);
    }
    visited[cur] = false;
}
int main() {
    cin >> n >> m;
    rep(i, m) {
        int a, b; cin >> a >> b;
        a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0, 0);
    cout << cnt;
}
