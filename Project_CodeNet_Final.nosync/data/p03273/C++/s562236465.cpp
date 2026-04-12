#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
  int h, w; cin >> h >> w;
  vector<string> b(h); rep(i, h) cin >> b[i];
  vector<bool> hf(h), wf(w);
  rep(i, h) rep(j, w) if (b[i][j] == '#') {
        hf[i] = true;
        wf[j] = true;
      }
  rep(i, h) if (hf[i]) {
    rep(j, w) if (wf[j]) {
        cout << b[i][j];
      }
    cout << endl;
  }
}
