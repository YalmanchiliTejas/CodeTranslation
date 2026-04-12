#include <bits/stdc++.h>
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define dump(x) cout << #x << " = " << (x) << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<int> A;
  REP(i, N) { A.push_back(i); }
  vector<vector<bool>> graph(N, vector<bool>(N, false));
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  int ans = 0;
  do {
    if(A[0] != 0) break;
    bool ok = true;
    REP(i, N - 1) {
      if(!graph[A[i]][A[i + 1]]) {
        ok = false;
        break;
      }
    }
    if(ok) { ans++; }
  } while(next_permutation(all(A)));
  cout << ans << endl;
  return 0;
}