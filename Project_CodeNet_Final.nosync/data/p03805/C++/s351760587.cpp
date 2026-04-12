#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  bool map[10][10];
  memset(map, false, sizeof(map));
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    map[a][b] =true; map[b][a] = true;
  }
  
  vector<int> path(N);
  rep(i, N)  path[i] = i;
  
  int count = 0;
  do {
    if (path[0] != 0) continue;
    
//    rep(i, N)  cout << path[i];
    
    rep(i, N-1) {
      int j = path[i+1];
      if (map[path[i]][j] == true) {
        if (i == N-2)  {count++;// rep(k, N) cout << path[k];
                       }
        continue;
      }
      else break;
    }
  } while (next_permutation(path.begin(), path.end()));
  
  
  cout << count << endl;
}
    
      