#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;

int N, M;

vector<int> dist;

void dfs(Graph& _G, int _v, int _cd, int& _counter){
  dist[_v] = _cd;
  bool is_all_checked = true;
  for(auto nv: _G[_v]){
    if(dist[nv]!=-1)continue;
    dfs(_G, nv, _cd+1, _counter);
    is_all_checked = false;
  }
  if(is_all_checked){
    if(dist[_v] == N-1) _counter+=1;
  }
  dist[_v] = -1;
}

int main(){

  cin >> N >> M;
  Graph G(N);
  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dist.assign(N, -1);

  int counter;
  counter=0;

  dfs(G, 0, 0, counter);

  cout << counter << endl;

  return 0;
}
