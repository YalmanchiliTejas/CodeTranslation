#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
    }
  }

  vector<bool> tate(h, false), yoko(w, false);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '#') {
        tate[i] = true;
      }
    }
  }

  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      if (s[i][j] == '#') {
        yoko[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    if (!tate[i]) {
      continue;
    }
    for (int j = 0; j < w; j++) {
      if (yoko[j]) {
        cout << s[i][j];
      }
    }
    cout << endl;
  }
}