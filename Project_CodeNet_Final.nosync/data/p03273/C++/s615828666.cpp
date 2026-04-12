#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<char> vec(H*W);

  for (int i = 0; i < H*W; i++) {
      char a;
      cin >> a;
      vec.at(i) = a;
    }
  int h = 0, w = 0;
  for (int i = H-1; i >= 0; i--) {
    for (int j = W-1; j >= 0; j--) {
      if (vec.at(i*W + j) == '#')
        break;
      else if (vec.at(i*W + j) == '.' && j > 0)
        continue;
      for (int k = 0; k < W; k++)
        vec.erase(vec.begin() + i*W + (W-k-1));
      h++;
    }
  }
    
  for (int j = W-1; j >= 0; j--) {
    for (int i = H-h-1; i >= 0; i--) {
      if (vec.at(j + i*(W-w)) == '#')
        break;
      else if (vec.at(j + i*(W-w)) == '.' && i > 0)
        continue;
      for (int k = 0; k < H-h; k++)
        vec.erase(vec.begin() + j + (H-h-1-k)*(W-w));
      w++;
    }
  }
        
  for (int i = 0; i < H-h; i++) {
    for (int j = 0; j < W-w; j++) {
      if (j != W-w-1)
        cout << vec.at(j+i*(W-w));
      else if (j == W-w-1)
        cout << vec.at(j+i*(W-w)) << endl;
    }
  }
}
