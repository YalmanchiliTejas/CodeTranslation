#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int N = 8;
const int M = N * (N-1) / 2;

vector<int> e[N + 2];
vector<int> visited;
static int ans = 0;


int judge(){
  int count;
  for(auto &elem : visited){
    if(elem != 1){
      return 0;
    }
  }
  return 1;
}

void dfs(int now){
  visited[now] = 1;
  if(judge() == 1){ ++ans; }
  for(auto &next : e[now]){
    if(visited[next] == 1) continue;
    //cout <<endl << "now : " << now << " next : " << next << " visited[next] : " << visited[next] ;
    dfs(next);
    visited[next] = 0;
  }
}

int main(){
  int a, b;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n ; i++){
    visited.emplace_back(0);
  }

  for(int i = 0; i < m ; i++){
    cin >> a >> b;
    --a;
    --b;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }

  dfs(0);

  cout << ans << endl;

  return 0;

}
