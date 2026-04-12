#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;

int N,M;
int ans;

vector<vector<int>> edge(8);
bool visited[8];

bool check(){
  int cnt = 0;
  REP(i,N){
    if(visited[i]==true)cnt++;
  }
  return cnt == N;
}

void dfs(int p, int n){
  if(visited[n])return;
//  fprintf(stderr, "%d %d %d\n",p,n,depth);
  visited[n] = true;
  if(check()){
    ans++;
    visited[n] = false;
    return;
  }
  REP(i,edge[n].size()){
    if(edge[n][i] == p)continue;
    dfs(n, edge[n][i]);
  }
  visited[n] = false;
}


int main(){
  cin >> N >> M;
  REP(i,M){
    int a,b;
    cin >> a >> b;
    a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  // REP(i,N){
  //   cout << i  << ": ";
  //   REP(j,edge[i].size()){
  //     cout << edge[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  REP(i,N)visited[i]=false;
  visited[0]=true;
  ans = 0;
  REP(i,edge[0].size()){
    dfs(0, edge[0][i]);
  }
  cout << ans << endl;

}

