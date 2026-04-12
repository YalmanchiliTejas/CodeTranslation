#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int> > g(10, vector<int>(10));

int dfs(int v/*現在の探索要素*/, int bit/*探索状態*/) {
  bit |= (1<<(v-1));

  if(bit == ((1<<N)-1)) return 1;

  int count = 0;
  for(int i = 0; i < g[v].size(); i++) {
    if(g[v][i] != 1) continue;
    if((bit>>(i-1))&1) continue; //もしも探索済みならcontinue
    count += dfs(i, bit);
  }
  return count;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;

  for(int i = 0; i < M; i++ ) {
    int a, b;
    cin >> a >> b;
    g[a][b] = 1;
    g[b][a] = 1;
  }

  cout << dfs(1, 0) << endl;


}
