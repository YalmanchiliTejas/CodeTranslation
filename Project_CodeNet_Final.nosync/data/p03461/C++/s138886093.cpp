#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int a, b;
int d[105][105];

bool ok(int i, int j, int x, int y) {
  int c = d[i][j] - i*x - j*y;
  for (int i1 = 1; i1 <= a; ++i1) for (int j1 = 1; j1 <= b; ++j1) {
    if (c + i1 * x + j1 * y < d[i1][j1]) {
      return 0;
    }
  }
//  cerr << i << ' ' << j << ' ' << x << ' ' << y << ' ' << c << endl;
  return 1;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> a >> b;
  int maxd = 0;
  for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) {
    cin >> d[i][j];
    maxd = max(maxd, d[i][j]);
    if ((i > 1 && d[i][j] < d[i-1][j]) || (j > 1 && d[i][j] < d[i][j-1])) {
      cout << "Impossible\n"; return 0;
    }
  }
  vector<vii> res(a + 1, vii(b + 1));
  int T = maxd;
  for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) {
    bool found = 0;
    for (int x = 0; x <= T && !found; ++x) for (int y = 0; i*x+j*y <= d[i][j]; ++y) {
      if (ok(i, j, x, y)) {
        res[i][j] = pii(x, y);
        found = 1; break;
      }
    }
    if (!found) {
      cout << "Impossible\n"; return 0;
    }
  }
  cout << "Possible\n";
  int s = 0, t = 2 * (T + 1) - 1;
  vector<array<int, 3>> e;
  for (int i = 0; i < T; ++i) {
    e.push_back({i, i + 1, -1});
    e.push_back({t - i - 1, t - i, -2});
  }
  set<pii> used;
  for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) {
    if (used.count(res[i][j])) continue;
    used.insert(res[i][j]);
    int c = d[i][j] - res[i][j].first * i - res[i][j].second * j;
    assert(c >= 0 && c <= 100);
    e.push_back({res[i][j].first, t - res[i][j].second, c});
  }
/*  for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) {

  }*/
  cout << t + 1 << ' ' << e.size() << endl;
  for (auto v : e) {
    cout << v[0] + 1 << ' ' << v[1] + 1 << ' ';
    if (v[2] >= 0) cout << v[2];
    else cout << (v[2] == -1 ? "X" : "Y");
    cout << endl;
  }
  cout << s + 1 << ' ' << t + 1 << endl;
  return 0;
}