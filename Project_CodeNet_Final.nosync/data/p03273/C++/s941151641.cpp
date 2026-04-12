#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

bool line[101], row[101]; 
char f[101][101];
int main() {
  int h, w; cin >> h >> w;
  rep(i,h) rep(j,w) cin >> f[i][j];

  rep(i,h) {
    bool allb = true;
    rep(j,w) {
      if (f[i][j] != '.') allb = false;
    }
    if (allb) line[i] = true;
    else line[i] = false;
  }
  rep(j,w) {
    bool allb = true;
    rep(i,h) {
      if (f[i][j] != '.') allb = false;
    }
    if (allb) row[j] = true;
    else row[j] = false;
  }

  rep(i,h) {
    rep(j,w) {
      if (line[i] || row[j]) continue;
      else cout << f[i][j];
    }
    if (!line[i])cout << endl;
  }
    return 0;
}