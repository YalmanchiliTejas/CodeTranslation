#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for(ll i=0; i<N; ++i)

ll max(ll a, ll b) {return a < b ? b : a; }

void dfs(vector<vector<int>>& aj, unordered_set<int>& remainings, int& accm, int current) {
  if(remainings.size() == 0) {
    ++accm;
    return;
  }
  
  for(int j = 0; j < aj[current].size(); ++j) {
    if(aj[current][j] && remainings.find(j) != remainings.end()) {
      //隣接していてまだ見ていない
      remainings.erase(j);
      dfs(aj, remainings, accm, j);
      remainings.insert(j);
    }
  }
}

int main() {
  int N, M;
  
  cin >> N >> M;
  vector<vector<int>> aj(N, vector<int>(N));
  for(int i=0; i<M; ++i) {
    int a, b;
    cin >> a >> b;
    aj[a-1][b-1] = 1;
    aj[b-1][a-1] = 1;
  }
  
  //DFSでパスを探す
  //隣接行列に変換したほうが探索が楽か.そうでもない．好みの問題．
  unordered_set<int> rem;
  for(int i=1; i<N; ++i) rem.insert(i);
  int accm = 0;
  
  dfs(aj, rem, accm, 0);
  
  cout << accm << endl;
  
  return 0;
}