#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = 1e18;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  vector<int> oh(h, 0), ow(w, 0);

  for (int i = 0; i < h; i++) {
    bool ok = false;
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') ok = true;
    }
    if (!ok) oh[i] = 1;
  }
  for (int i = 0; i < w; i++) {
    bool ok = false;
    for (int j = 0; j < h; j++) {
      if (a[j][i] == '#') ok = true;
    }
    if (!ok) ow[i] = 1;
  }

  for (int i = 0; i < h; i++) {
    bool f = false;
    for (int j = 0; j < w; j++) {
      if (oh[i] || ow[j]) continue;
      f = true;
      cout << a[i][j];
    }
    if (f) cout << endl;
  }
  return 0;
} 