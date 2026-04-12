#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string A[8];
  for (int i = 0; i < H; i++) cin >> A[i];
  int pass = 0;
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (A[i][j] == '#') pass++;
  if (pass == H + W - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  return 0;
}