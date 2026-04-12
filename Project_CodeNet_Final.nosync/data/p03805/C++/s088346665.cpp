#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define SZ(a) ((int)(a).size())
#define PB(a) push_back(a)
#define EMP emplace
#define EMPB(...) emplace_back(__VA_ARGS__)
#define MP(a, b) make_pair(a, b)
#define MT(...) make_tuple(__VA_ARGS__)
#define Bit(n) (1LL << (n))
using namespace std;
using pii = pair<int, int>;
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const int INF = 1LL << 30;
const double EPS = 1e-10;

int N, M;
vector<int> G[8];
int used[8];

int dfs(int v) {
  int flag = 1;
  for (int i = 0; i < N; i++) {
    if (i != v && !used[i]) flag = 0;
  }
  if (flag) return 1;
  int res = 0;
  for (int nv : G[v]) {
    if (used[nv]) continue;
    used[nv] = 1;
    res += dfs(nv);
    used[nv] = 0;
  }
  return res;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> M;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].PB(b);
    G[b].PB(a);
  }
  used[0] = 1;
  cout << dfs(0) << endl;

  return 0;
}