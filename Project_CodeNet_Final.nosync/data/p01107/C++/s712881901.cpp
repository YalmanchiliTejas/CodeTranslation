#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
bool search(int n, int m, int distr, int distc, vector<vector<bool>> &sel, int dir, int r, int c) {
  if(r == distr && c == distc) return true;
  if(0 <= r + dr[(dir + 1) % 4] && r + dr[(dir + 1) % 4] < n &&
      0 <= c + dc[(dir + 1) % 4] && c + dc[(dir + 1) % 4] < m &&
      sel[r + dr[(dir+1)%4]][c + dc[(dir+1)%4]]) {
    sel[r + dr[(dir+1)%4]][c + dc[(dir+1)%4]] = false;
    bool ok = search(n, m, distr, distc, sel, (dir + 1) % 4, r + dr[(dir + 1) % 4], c + dc[(dir + 1) % 4]);
    if(ok) return true;
  }
  if(0 <= r + dr[dir] && r + dr[dir] < n &&
      0 <= c + dc[dir] && c + dc[dir] < m &&
      sel[r + dr[dir]][c + dc[dir]]) {
    sel[r + dr[dir]][c + dc[dir]] = false;
    bool ok = search(n, m, distr, distc, sel, dir, r + dr[dir], c + dc[dir]);
    if(ok) return true;
  }
  if(0 <= r + dr[(dir + 3) % 4] && r + dr[(dir + 3) % 4] < n &&
      0 <= c + dc[(dir + 3) % 4] && c + dc[(dir + 3) % 4] < m &&
      sel[r + dr[(dir + 3) %4]][c + dc[(dir + 3) % 4]]) {
    sel[r + dr[(dir + 3) % 4]][c + dc[(dir + 3) % 4]] = false;
    bool ok = search(n, m, distr, distc, sel, (dir + 3) % 4, r + dr[(dir + 3) % 4], c + dc[(dir + 3) % 4]);
    if(ok) return true;
  }
  return false;
}
bool solve() {
  int n, m; cin >> n >> m;
  if(n == 0) return false;
  vector<vector<bool>> sel(n, vector<bool>(m, false));
  for(int i=0;i<n;++i) {
    for(int j=0;j<m;++j) {
      char tmp; cin >> tmp;
      sel[i][j] = tmp == '.';
    }
  }
  bool ok = search(n, m, n-1, 0, sel, 0, 0, 0);
  if(ok) ok = search(n, m, n-1, m-1, sel, 3, n-1, 0);
  if(ok) ok = search(n, m, 0, m-1, sel, 2, n-1, m-1);
  if(ok) ok = search(n, m, 0, 0, sel, 1, 0, m-1);
  cout << (ok ? "YES" : "NO") << endl;
  return true;
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  while(solve()) {}
}

