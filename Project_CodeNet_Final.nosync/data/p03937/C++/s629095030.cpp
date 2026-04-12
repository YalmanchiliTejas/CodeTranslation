#include <iostream>
#include <string>
using namespace std;
int H, W;
int main() {
  cin >> H >> W;
  int cnt = 0;
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      char c;
      cin >> c;
      if (c == '#') ++cnt;
    }
  }
  cout << (cnt == H + W - 1 ? "P" : "Imp") << "ossible" << endl;
  return 0;
}
