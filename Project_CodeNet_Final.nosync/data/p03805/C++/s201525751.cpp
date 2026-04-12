#include <algorithm>
#include <iostream>

using namespace std;

int n, m, ans;
bool edge[8][8];
int perm[8];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[a][b] = edge[b][a] = true;
  }
  
  for (int i = 0; i < n; i++) {
    perm[i] = i;
  }
  
  do {
    bool f = true;
    for (int i = 0; i < n-1; i++) {
      if (not edge[perm[i]][perm[i+1]]) {
        f = false;
      }
    }
    if (f) ans++;
  } while (next_permutation(perm + 1, perm + n));
  
  cout << ans << endl;
  return 0;
}