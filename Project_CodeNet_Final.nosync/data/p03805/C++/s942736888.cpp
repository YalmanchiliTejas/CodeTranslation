#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;

void dfs(const Graph& G, int v, int& cnt) {

    bool end = true;
    for (int i = 0; i < seen.size(); i++) {
        if (!seen[i] && i !=v ) {
            end = false;
        }
    }
    if (end) {
        cnt++;
        return;
    }


    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, cnt); // 再帰的に探索
    }

    seen[v] = false;
    return;
}

int main()
{
    int N, M; cin >> N >> M;   // 頂点数と辺数

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);

    int ans = 0;
    dfs(G, 0, ans);

    cout << ans << endl;
    return 0;
}