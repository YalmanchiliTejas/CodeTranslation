#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const ll MOD = 1000000007;
const int nmax = 8;
int graph[nmax][nmax] = {};
int dfs(int v, int N, vector<bool > visited){
  bool all = true;
  REP(i, N){
    if(!visited[i]) {
      all = false;
      break;
    }
  }
  if(all) return 1;

  int ret = 0;
  for(int i = 0; i < N; i++){
    if(graph[v][i] == 1 && visited[i] == false){
      //      cout << "v, i = " << v <<", " << i << endl;
      visited[i] = true;
      ret += dfs(i, N, visited);
      visited[i] = false;
    }
  }
  return ret;
}
int main(){
  int N, M;
  cin >> N >> M ;
  //  int Mat[N][N] = {};
  vector<pair<int, int > > g(M);
  REP(i, M) cin >> g[i].first >> g[i].second;
  REP(i, M) {
    graph[g[i].first - 1][g[i].second - 1] = 1;
    graph[g[i].second - 1][g[i].first - 1] = 1;
  }
  //  REP(i, N){
  //    REP(j, N){
  //      cout << graph[i][j] << "\t";
  //    }
  //    cout << "\n" ;
  //  }
  vector<bool > v(N , false);
  v[0] = true;
  //  REP(i, N) cout << v[i] << "\t";
  cout << endl;
  cout << dfs(0, N, v)<< endl;
}
