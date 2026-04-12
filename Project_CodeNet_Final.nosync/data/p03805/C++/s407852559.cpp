#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;

int perm[8];
bool used[8];
bool mat[8][8];
int cnt;

void permutation(int n, int d) {
  if (d == n) { ++cnt; return;}

  for (int i = 1; i < n; ++i) {
    if (used[i] || !mat[perm[d-1]][i]) continue;
    perm[d] = i;
    used[i] = true;
    permutation(n, d+1);
    used[i] = false;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    mat[a][b] = mat[b][a] = true;
  }

  permutation(n, 1);
  cout << cnt << endl;
  return 0;
}