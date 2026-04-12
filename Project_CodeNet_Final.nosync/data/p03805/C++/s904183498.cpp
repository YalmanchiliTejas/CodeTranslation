#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 8;

int n, m;
int G[N][N];
int perm[N];

int main() {
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b; a--; b--;
    G[a][b] = G[b][a] = 1;
  }
  rep(i, n) perm[i] = i;
  int ans = 0;
  do {
    bool exist = true;
    rep(i, n - 1) {
      if (G[perm[i]][perm[i + 1]] == 0) exist = false;
    }
    if (exist) ans++;
  } while (next_permutation(perm + 1, perm + n));
  cout << ans << endl;
  return 0;
}