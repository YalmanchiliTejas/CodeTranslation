#include <bits/stdc++.h>
#define rep(i,n) for (int i =0; (int)i<n; i++) 
using namespace std;

int N,M; bool ab[10][10],seen[10];

int dfs(int v, int N, bool seen[10]) {
  bool allVisited = true;
  rep(i,N) {
    if (seen[i] == false) allVisited = false;
  }
  if (allVisited) return 1;
  int ret =0;
  rep(i,N) {
    if (ab[v][i] == false) continue;
    if (seen[i]) continue;
    seen[i] = true;
    ret += dfs(i,N,seen);
    seen[i] = false;
  }
  return ret;
}

int main(){
  cin >> N >> M;
  rep(i,M) {
    int a,b; cin >> a >> b; 
    ab[a-1][b-1] = ab[b-1][a-1] = true;
  }
  
  rep(i,N) seen[i] = false;
  seen[0] = true;
  cout << dfs(0,N,seen) << endl;
}