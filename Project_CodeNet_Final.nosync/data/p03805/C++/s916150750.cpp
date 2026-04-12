#include <bits/stdc++.h>
using namespace std;

int ans=0, N, M, a, b;
vector<vector<int>> G;

void search(int s, vector<int> chk) {
  chk[s]=1;
  if(accumulate(chk.begin(), chk.end(), 0)==N) {ans++; return;}
  for (auto t : G[s]){
    if(chk[t]==1) continue;
    else {
      search(t, chk);
    }
  }
  return;
}

int main() {
  cin >> N >> M;
  G = vector<vector<int>>(N, vector<int>(0));
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> chk(N,0);
  search(0, chk);
  
  cout << ans << "\n";
  return 0;
}