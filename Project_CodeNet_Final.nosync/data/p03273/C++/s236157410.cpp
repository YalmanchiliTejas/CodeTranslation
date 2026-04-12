#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
  int h, w;
  cin >> h >> w;

  vector<bool> markrow(h, false), markcol(w, false);

  vector<string> mas(h);
  for (int i = 0; i < h; i++) cin >> mas[i];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (mas[i][j] == '#') {
        markrow[i] = true;
        markcol[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (markrow[i] && markcol[j]) cout << mas[i][j];
    }
    if (markrow[i]) cout << endl;
  }
}
