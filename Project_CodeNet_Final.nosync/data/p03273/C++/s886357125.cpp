#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>

using namespace std;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  
  char map[h][w];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> map[i][j];
    }
  }
  
  vector<bool> height(h, false);
  vector<bool> width(w, false);
  
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (map[i][j] == '#') {
        height[i] = true;
        break;
      }
    }
  }
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (map[j][i] == '#') {
        width[i] = true;
        break;
      }
    }
  }
  
  for (int i = 0; i < h; i++) {
    if(!height[i]) {
      continue;
    }
    for (int j = 0; j < w; j++) {
      if(!width[j]) {
        continue;
      }
      cout << map[i][j];
    }
    cout << endl;
  }
  
  return 0;
}
