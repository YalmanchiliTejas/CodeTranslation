#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <vector>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
char str[105][105];
int vis[105][105];

int main (int argc, char **argv) {
  int h, w;
  std::cin >> h >> w;
  for (int i=0; i < h; i++) {
    for (int j=0; j < w; j++) {
      std::cin >> str[i][j];
    }
  }

  memset(vis, 0, sizeof(vis));

  for (int i=0; i < h; i++) {
    int sum = 0;
    for (int j=0; j < w; j++) {
      if (str[i][j] == '.') {
        sum++;
      }
    }
    if (sum == w) {
      for (int j=0; j < w; j++) {
        vis[i][j] = 1;
      }
    }
  }

  for (int i=0; i < w; i++) {
    int sum = 0;
    for (int j=0; j < h; j++) {
      if (str[j][i] == '.') {
        sum++;
      }
    }

    if (sum == h) {
      for (int j=0; j < h; j++) {
        vis[j][i] = 1;
      }
    }
  }

  for (int i=0; i < h; i++) {
    bool flag = false;
    for (int j=0; j < w; j++) {
      if (!vis[i][j]) {
        std::cout << str[i][j];
        flag = true;
      }
    }
    if (flag) {
      std::cout << std::endl;
    } 
  }
  return 0;
}
