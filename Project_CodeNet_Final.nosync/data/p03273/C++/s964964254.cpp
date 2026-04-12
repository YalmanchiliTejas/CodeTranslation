#include <bits/stdc++.h>

using namespace std;

void Compress(vector<string>& B, int H, int W, int x, int y) {
  bool can_compress = true;
  for (int x2 = 0; x2 < W; x2++) {
    if (B[y][x2] == '#') {
      can_compress = false;
      break;
    }
  }

  if (can_compress) {
    for (int x2 = 0; x2 < W; x2++) {
      B[y][x2] = ' ';
    }
  }

  can_compress = true;
  for (int y2 = 0; y2 < H; y2++) {
    if (B[y2][x] == '#') {
      can_compress = false;
      break;
    }
  }

  if (can_compress) {
    for (int y2 = 0; y2 < H; y2++) {
      B[y2][x] = ' ';
    }
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> B(H);
  for (int y = 0; y < H; y++) cin >> B[y];

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (B[y][x] != '.') continue;
      Compress(B, H, W, x, y);
    }
  }

  for (int y = 0; y < H; y++) {
    string S = "";
    for (int x = 0; x < W; x++) {
      if (B[y][x] != ' ') S += B[y][x];
    }
    if (S != "") cout << S << "\n";
  }

  return 0;
}
