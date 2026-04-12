#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <climits>
#define ll long long
#define LIM 1000
using namespace std;
char v[LIM][LIM];
int main() {
  ll h, w;
  cin >> h >> w;
  string s;
  for (int y = 0; y < h; y++) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      v[y][i] = s[i];
    }
  }
  int right = 0;
  int down = 0;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (v[y][x] == '#') {
        int yy = y + 1;
        int xx = x + 1;
          if (xx < w && v[y][xx] == '#') {
            right++;
          }
          if (yy < h && v[yy][x] == '#') {
            down++;
          }
      }
    }
  }
  if (right == w - 1 && down == h - 1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}
