#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int cnt;
int n,m;

void dfs(vector<vector<int>> &g, int v, int c,vector<bool> seen){
  seen[v] = true; //vを訪問済みにする
  if (c == n){
    cnt++; //もし到達ノード数が全てのノード数と一致していたらcountする。
    return;
  }
  //vに繋がっている next_vを探索する。
  for (auto next_v : g[v]){
    if (seen[next_v]) continue; //もしすでにnext_vが探索済みであったら、skip
    dfs(g, next_v, c+1,seen); //もしそうでなければ再帰的に探索
  }
}

int main() {
  cin >> n >> m;
  
  vector<vector<int>> g(n);
  cnt = 0;
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  vector<bool> seen(n, false); //全頂点をfalse、つまり未訪問で初期化。
  dfs(g,0,1,seen);
  
  cout << cnt;
  return 0;
}