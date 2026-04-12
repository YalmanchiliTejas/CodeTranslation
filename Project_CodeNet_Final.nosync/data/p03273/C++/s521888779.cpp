#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int H, W; cin >> H >> W;
  string a[H]; rep(i,H) cin >> a[i];

  bool h[H]; fill_n(h, H, true);
  bool w[W]; fill_n(w, W, true);

  rep(i, H) {
    bool ok = true;
    rep(j, W) if (a[i][j]=='#') ok = false;
    if (ok) h[i] = false;
  }
  rep(i, W) {
    bool ok = true;
    rep(j, H) if (a[j][i]=='#') ok = false;
    if (ok) w[i] = false;
  }

  rep(i, H) {
    if (h[i]) {
      rep(j, W) if (w[j]) cout << a[i][j];
      cout << endl;
    }
  }
  return 0;
}