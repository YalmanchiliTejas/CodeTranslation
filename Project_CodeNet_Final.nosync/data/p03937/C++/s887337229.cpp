#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <limits>
#include <math.h>
#include <string>
#include <map>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; ++i) cin >> a[i];

  int pr = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == '#') {
	if (j < pr) {
	  puts("Impossible");
	  return 0;
	}
      pr = j;
      }
    }
  }
  puts("Possible");
  return 0;
}
