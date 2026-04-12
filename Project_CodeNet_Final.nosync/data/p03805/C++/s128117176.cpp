#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using info = vector<int>;
Graph G;
info v;

int main() {
  int N, M;
  cin >> N >> M;
  G.assign(N+1, info(M+1));
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  } 

  for (int i = 1; i <= N; ++i) {
    v.push_back(i);
  }

  int count = 0;
  do {
    if (v.at(0) != 1) break;
    
    bool cont = false;
    for (int i = 0; i < N-1; ++i) {
      cont = false;
      for (auto nv : G[v.at(i)]) {
        if (nv == v.at(i+1)) {
          cont = true;
          break;
        }
      }
      if (!cont) break;
    }
    if (cont) count++;
    
  } while (next_permutation(v.begin(), v.end()));

  cout << count << endl;
}
