#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using Graph = vector<vector<int>>;
int ans=0;
int N,M;

// 深さ優先探索
void dfs(const Graph &G, int v,vector<int> seen) {
    seen[v] = 1; // v を訪問済にする
    if(accumulate(seen.begin(),seen.end(),0)==N)ans++;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
      a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
  vector<int> seen;
    seen.assign(N, 0); // 全頂点を「未訪問」に初期化
    dfs(G, 0, seen);
  cout << ans << endl;
}