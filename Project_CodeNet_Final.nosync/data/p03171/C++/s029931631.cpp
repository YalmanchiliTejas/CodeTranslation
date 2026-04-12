#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) ((int)(a).size())
#define PB(a) push_back(a)
#define EB(...) emplace_back(__VA_ARGS__)
#define MP(a, b) make_pair(a, b)
#define MT(...) make_tuple(__VA_ARGS__)
using namespace std;
using pii = pair<int, int>;
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const int INF = 1LL << 60;
const double EPS = 1e-10;

int N;
int a[3010];
int used[2][3010][3010];
int memo[2][3010][3010];

int dfs(int t, int L, int R) {
  if (L > R) return 0;
  if (used[t][L][R]) return memo[t][L][R];
  used[t][L][R] = 1;
  if (t == 0) return memo[t][L][R] = max(dfs(t^1,L+1,R)+a[L], dfs(t^1,L,R-1)+a[R]);
  else return memo[t][L][R] = min(dfs(t^1,L+1,R)-a[L], dfs(t^1,L,R-1)-a[R]);
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  REP(i, N) cin >> a[i];
  cout << dfs(0, 0, N-1) << endl;

  return 0;
}