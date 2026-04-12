#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>


using namespace std;

int H, W;
int A[9][9];

int startY = -1, startX;

int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };

int dfs(int y, int x) {
  int ret = 0;
  for (int i = 0; i < 2; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= H) {
      continue;
    } 
    if (nx < 0 || nx >= W) {
      continue;
    }
    if (A[ny][nx] == 0) {
      continue;
    } else {
      ret = 1 + dfs(ny, nx);
    }
  }

  return ret;
}


int main() {
  cin >> H >> W;
  int count = 0;
  for (int y = 0; y < H; y++) {
    for (int x =  0; x < W; x++) {
      char c;
      cin >> c;
      if (c == '#') {
        A[y][x] = 1;
        if (startY == -1) {
          startY = y;

        }
        count++;
      }  
    }
  }

  int d = 1 + dfs(startY, startX);
  if (d == count) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }

  return 0;
}