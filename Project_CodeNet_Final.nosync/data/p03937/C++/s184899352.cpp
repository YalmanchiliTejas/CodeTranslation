#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc007_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int H, W;
vector<vector<char>> r;

bool dfs(vector<vector<char>> &c, int h, int w, vector<vector<char>> d) {
  d[h][w] = '#';
  if (h == H - 1 && w == W - 1) {
    r = d;
    return true;
  }
  bool ok = false;
  if (h + 1 < H && c[h + 1][w] == '#') {
    ok |= dfs(c, h + 1, w, d);
  }
  if (w + 1 < W && c[h][w + 1] == '#') {
    ok |= dfs(c, h, w + 1, d);
  }
  return ok;
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  cin >> H >> W;

  vector<vector<char>> c(H, vector<char>(W));
  vector<vector<char>> d(H, vector<char>(W, '-'));
  rep(i, H) rep(j, W) { cin >> c[i][j]; }
  bool ok = dfs(c, 0, 0, d);

  int cntr = 0, cntc = 0;
  if (ok) {
    rep(i, H) rep(j, W) {
      if (c[i][j] == '#') cntc++;
      if (r[i][j] == '#') cntr++;
    }
    ok = cntc == cntr;
  }
  cout << (ok ? "Possible" : "Impossible") << endl;
}