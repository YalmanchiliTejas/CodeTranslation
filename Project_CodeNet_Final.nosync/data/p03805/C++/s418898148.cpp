#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    A[a].push_back(b);
    A[b].push_back(a);
  }
  ll ans = 0;
  vector<int> p(N);
  REP(i, N) p[i] = i;
  do {
    if (p[0] != 0) continue;
    bool b = true;
    REP(i, N - 1) {
      bool t = false;
      REP(j, A[p[i]].size()) {
        if (A[p[i]][j] == p[i + 1]) t = true;
      }
      if (!t) b = false;
    }
    if (b) ans++;
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << endl;
}