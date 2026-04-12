#include <iostream>
#include <algorithm>
using namespace std;


int main () {
  int n, m;
  int a[100], b[100];
  int n_perm[10];
  int ans = 0;

  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> a[i] >> b[i];

  for (int i = 0; i < n; i++) {
    n_perm[i] = i;
  }

  do {
    if (n_perm[0] != 0) break;
    bool can2 = true;
    for (int i = 0; i < n-1; i++) {
      int pos1 = n_perm[i] + 1;
      int pos2 = n_perm[i+1] + 1;
      bool can = false;
      for (int k = 0; k < m; k++) {
        if ((a[k] == pos1 && b[k] == pos2) || (b[k] == pos1 && a[k] == pos2)) {
          can = true;
        }
      }
      if (!can) can2 = false;
    }
    if (can2) ans++;
  } while (next_permutation(n_perm, n_perm + n));

  cout << ans << endl;
}
