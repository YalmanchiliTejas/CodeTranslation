#include <bits/stdc++.h>
using namespace std;
int G[8][8];


int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      G[i][j] = 0;
    }
  }
  
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b; a--; b--;
    G[a][b] = 1; G[b][a] = 1;
  }
  
  vector<int> v;
  for (int i = 0; i < N; i++) {
    v.push_back(i);
  }
  
  int ans = 0;
  do {
    bool ok = true;
    for (int i = 0; i < N-1; i++) {
      if (G[v[i]][v[i+1]] == 0) {ok = false;}
    }
    if (ok) {ans++;}
  } while (next_permutation(v.begin()+1, v.end()));
  
  cout << ans << endl;
}