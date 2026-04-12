#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

// 深さ優先探索
int ans = 0;
vector<bool> seen;
void dfs(const Graph& G, int v, int& ans) {
    seen[v] = true; // v を訪問済にする

    bool end = true;
    for (int i = 0; i < seen.size(); i++) {
        if (i == v) continue;
        if (!seen[i]) end = false;
    }
    if (end) {
        ans++;
        seen[v] = false;
        return;
    }
    
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) {
            continue; // next_v が探索済だったらスルー
        }
        dfs(G, next_v, ans); // 再帰的に探索        
    }

    seen[v] = false;
}

int main() {

    // 頂点数と辺数
    int N, M; cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;

    // 頂点 s をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0, ans);
	
    cout << ans << endl;
	return 0;
}