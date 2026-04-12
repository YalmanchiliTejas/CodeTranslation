#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int ans = 0;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph& G, int v, int n, int cnt) {
    seen[v] = true; // v を訪問済にする
    if (cnt == n - 1) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if(!seen[i]){
                ok = false;
            }      
        }
        if (ok) ans++;
        return;
    }

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        cnt++;
        dfs(G, next_v,n, cnt); // 再帰的に探索
        cnt--;
        seen[next_v] = false;
    }
}

int main() {

    // 頂点数と辺数
    int n, m; cin >> n >> m;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    // 頂点 s をスタートとした探索
    int cnt = 0;
    seen.assign(n, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, n, cnt);

    cout << ans << endl;
	return 0;
}