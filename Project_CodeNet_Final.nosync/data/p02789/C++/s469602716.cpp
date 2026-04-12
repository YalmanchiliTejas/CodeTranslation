#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define debug2(x, y)                       \
  cerr << "(" << #x << "," << #y << ") = " \
       << "(" << x << "," << y << ")\n"
#define all(x) x.begin(), x.end()
#define each(a, x) for (auto& a : (x))
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define int long long
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
const int MX = 1e5 + 5, INF = 5LL << 57, MOD = 1e9 + 7;

int N, M;
string S;
vi va, vb;

void input() {
  ;
  ;
  cin >> N >> M;
}
void solve() {
  ;
  cout << (N == M ? "Yes" : "No");
  ;
}
signed main() {
  input();
  solve();
  return 0;
}