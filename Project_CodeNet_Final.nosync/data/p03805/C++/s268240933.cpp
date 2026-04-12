#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int nmax = 8;
bool to[nmax][nmax];

int dfs(int v,int n,bool visited[nmax]){
  bool all_visited = true;

  rep(i,n){//全ての頂点を訪れたか調べる
    if(visited[i]==false) all_visited = false;
  }

  /*ベースケース*/
  if(all_visited) return 1;//全て訪れたなら

  /*再帰ステップ*/
  int res = 0;

  rep(i,n){//隣接する頂点について調べる
    if(to[v][i]==false) continue;//隣接していない頂点ならとばす
    if(visited[i]) continue;//訪問済み頂点ならとばす

    visited[i] = true;//一旦訪問済みにする
    res += dfs(i,n,visited);//さらに先の頂点について調べる
    visited[i] = false;//未訪問に戻す
  }

  return res;
}

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    to[a][b] = true;
    to[b][a] = true;
  }

  bool visited[nmax];
  rep(i,n) visited[i] = false;

  visited[0] = true;
  cout << dfs(0,n,visited) << endl;

  return 0;
}