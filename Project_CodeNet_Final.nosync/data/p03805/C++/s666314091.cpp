#include <iostream>
#include <vector>
#include <algorithm>  // next_permutation(順列)
#include <numeric>
using namespace std;

bool G[10][10];   // グラフを隣接行列で管理

int main() {
  int N, M;
  cin >> N >> M;
  for ( int i = 0; i < M; i++ ) {
    int a, b;
    cin >> a >> b;
    G[a-1][b-1] = true;
    G[b-1][a-1] = true;
  }
  
  // 順列
  vector<int> ord(N);
  for ( int i = 0; i < N; i++ ) ord[i] = i;
  
  int ans = 0;
  do {
    if ( ord[0] != 0 ) break;   //始点は1である必要あり
    
    bool ok = true;
    for ( int i = 0; i + 1 < N; i++ ) {
      int from = ord[i];
      int to = ord[i+1];
      if ( !G[from][to] ) ok = false;
    }
    if ( ok ) ans++;
  } while ( next_permutation(ord.begin(), ord.end()) );   //next_permutationを利用するには昇順に並び替えておく必要あり

  cout << ans << endl;
}
