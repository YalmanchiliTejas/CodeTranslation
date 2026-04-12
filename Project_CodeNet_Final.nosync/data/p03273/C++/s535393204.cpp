#include <bits/stdc++.h>
#define dum(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> a(h, vector<char>(w));

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a.at(i).at(j);
    }
  }

  vector<bool> vh(h, false);
  vector<int> vw(w, false);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a.at(i).at(j) == '#') {
        vh.at(i) = true;
        vw.at(j) = true;
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    bool flag = false;
    for (int j = 0; j < w; ++j) {
      if (vh.at(i) && vw.at(j)) {
        cout << a.at(i).at(j);
        flag = true;
      }
    }
    if (flag) {
      cout << endl;
    }
  }
}