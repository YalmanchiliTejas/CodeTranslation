#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int MOD = 1000000007;
int INF = numeric_limits<int>::max() / 2;

using Graph = vector<vector<int>>;
int cou1 = 0;
int N, M;

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
  seen[v] = true; // v を訪問済みにする
  bool ok = true;
  for(int i=0;i<N;i++){
    if(!seen[i]) ok = false;
  }
  if(ok) cou1++;

  // vから行ける各頂点 next_v について
  for(auto nv : G[v]){
    if (seen[nv]) continue; // next_v が探索済みだったらスルー
    dfs(G, nv); // 再帰的に探索
  } 
  seen[v] = false;
}

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  
  Graph G(N);
  for(int i=0;i<M;i++){
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  seen.assign(N, false); // 全頂点を「未訪問」にして初期化
  dfs(G, 0);

  cout << cou1 << endl;

}