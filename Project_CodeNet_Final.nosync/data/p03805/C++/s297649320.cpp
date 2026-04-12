#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using Graph = vector<vector<int>>;

int n, m;
int ans = 0;
int c = 0;
vector<vector<int> > g;
vector<bool> seen;

void dfs(int i){
    seen[i] = true;
    c++;
    if(c == n) ans++;
    for(auto next : g[i]){
        if(seen[next]) continue;
        dfs(next);
    }
    seen[i] = false;
    c--;
}

int main() {
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    seen.resize(n + 1, false);
    dfs(1);
    cout << ans << endl;
}
