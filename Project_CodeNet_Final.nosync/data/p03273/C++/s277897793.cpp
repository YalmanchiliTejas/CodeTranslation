#include <bits/stdc++.h>

using namespace std;

int main()
{
  int H, W; cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; ++i) {
    cin >> a[i];
  }

  // delete row
  for (int i = 0; i < a.size();) {
    if (a[i].find('#') == string::npos) {
      a.erase(a.begin() + i, a.begin() + i + 1);
      continue;
    }

    ++i;
  }

  // delete column
  for (int w_i = 0; w_i < W;) {
    string tmp;
    for (int h_i = 0; h_i < a.size(); ++h_i) {
      tmp.push_back(a[h_i][w_i]);
    }

    if (tmp.find('#') == string::npos) {
      for (int k = 0; k < a.size(); ++k) {
        a[k].erase(w_i, 1);
      }
      W--;
      continue;
    }

    ++w_i;
  }

  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << endl;
  }

}