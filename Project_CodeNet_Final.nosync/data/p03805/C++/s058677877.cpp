#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'
#define int long long

int n,m,ans = 0;
vector<vector<int>> G;
bool visited[8];

void dfs(int i){
    if(visited[i]) return;
    visited[i] = true;
    for(auto j : G[i]){
        dfs(j);
    }

    bool flag = true;
    for(int j = 0; j < n; j++){
        if(!visited[j]) flag = false;
    }
    if(flag) ans++;
    visited[i] = false;
}

signed main() {
    cin >> n >> m;

    G.resize(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    cout << ans << endl;
}
