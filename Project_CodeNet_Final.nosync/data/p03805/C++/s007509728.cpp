#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

const int nmax = 8;
bool graph[nmax][nmax]; //接続状況を格納する隣接行列

//dfsでパスを全探索
//vが今いるパス、Nが頂点の数
int dfs(int v, int &N, bool visited[nmax]) { //1を返すのでint
  bool all_visited = true; 
  FOR(i,0,N) {
    if (visited[i] == false) all_visited = false; //一つでも訪れていない頂点があればfalseに
  }
  if (all_visited) {
    return 1; //全頂点を訪れていたら、題意を満たすので1を返す
  }
  //ここまでが一つの流れを表してる？
  
  int ret = 0;
  
  //すべての遷移先について調べる(再帰、dfs)
  FOR(i,0,N) {
    //頂点iが接続されていない、あるいは既に探索済みであればi+1に進む
    if (graph[v][i] == false) continue;
    if (visited[i]) continue;
    //iに遷移する
    visited[i] = true;
    //iからの遷移を試す
    ret += dfs(i,N,visited);
    //iのフラグを取り消す
    visited[i] = false;
  }
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;
  FOR(i,0,M) {
    int a,b;
    cin >> a >> b;
    //接続状況のグラフ
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }
  bool visited[nmax];
  
  //visitedをfalseで初期化
  FOR(i,0,N) visited[i] = false;
  visited[0] = true;
  
  //頂点0から始まるパスの数を出力
  cout << dfs(0,N,visited) << endl;
  return 0;
}