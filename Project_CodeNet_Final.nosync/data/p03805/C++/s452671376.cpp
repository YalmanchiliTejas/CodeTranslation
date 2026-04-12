#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int N, M; 
vector<bool> seen;
int ans;

bool check(){
    bool res = true;
    for(int i = 0; i < N; i++)
      if(!seen[i]) res = false;
    return res;
}

// 深さ優先探索
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする
  
    if(check()) ans++;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
        seen[next_v] = false;
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
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
  
    ans = 0;

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
  
    cout << ans << endl;  
    return 0;
}