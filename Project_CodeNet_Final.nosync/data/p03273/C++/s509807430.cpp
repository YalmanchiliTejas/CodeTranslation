#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, e) for (int i = (s); i < (int)(e); i++)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A;
  rep (i, H) {
    string s;
    cin >> s;
    A.push_back(s);
  }

  vector<int> h_ok;
  vector<int> w_ok;

  rep (h, H) {
    bool ok = false;
    rep (w, W) {
      ok |= A[h][w] == '#';
    }
    h_ok.push_back(ok);
  }
  rep (w, W) {
    bool ok = false;
    rep (h, H) {
      ok |= A[h][w] == '#';
    }
    w_ok.push_back(ok);
  }

  rep (h, H) {
    if (!h_ok[h]) continue;
    rep (w, W) {
      if (w_ok[w]) {
        cout << A[h][w];
      }
    }
    cout << endl;
  }
}