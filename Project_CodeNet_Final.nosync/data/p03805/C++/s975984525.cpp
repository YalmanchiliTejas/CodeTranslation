#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const int inf = int(1e10);
const int mod = int(1e9) + 7;


using Graph = vector<vector<int>>;
int n, m, res = 0;
Graph G(30);

void dfs(vector<bool> &seen, int v, int cnt){
    if(cnt == n - 1){
        res++;
        return;
    }
    seen[v] = true;
    for(auto next_v: G[v]){
        if(seen[next_v]) continue;
        dfs(seen, next_v, cnt + 1);
    }
    
    seen[v] = false;
}

int main(){
    cin >> n >> m;
    vector<bool> seen;
    seen.assign(n, false);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    dfs(seen, 0, 0);
    cout << res << endl;

}