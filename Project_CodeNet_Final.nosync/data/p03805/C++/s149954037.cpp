#include <bits/stdc++.h>
#define ll long long
#define REP(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (ll (i) = (a); (i) < (b); (i)++)
#define P pair<ll, ll>
#define VI vector<ll>
#define int long long
using namespace std;
int N, M;
vector<vector<bool>> e;

void solve() {
  vector<int> perm(N);
  REP (i, N) { perm[i] = i; }
  int ans = 0;
  do {
    bool hamilton = true;
    REP (i, N-1) {
      if (!e[perm[i]][perm[i+1]]) {
        hamilton = false;
      }
    }
    if (hamilton) {
      ans++;
    }
  } while (next_permutation(perm.begin() + 1, perm.end()));
  cout << ans << endl;
}

signed main() {
  cin >> N >> M;
  e = vector<vector<bool>>(N, vector<bool>(N, false));
  REP (i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    e[a][b] = true;
    e[b][a] = true;
  }

  solve();
}
