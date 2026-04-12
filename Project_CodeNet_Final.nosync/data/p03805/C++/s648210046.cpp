#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int n, m;
V<V<int> > g;
V<bool> seen;
int ans = 0, cnt = 0;

void dfs(int v){
    seen[v] = true;
    cnt++;
    if(cnt == n) ans++;
    for(auto next_v : g[v]){
        if(seen[next_v]) continue;
        dfs(next_v);
    }
    seen[v] = false;
    cnt--;

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
