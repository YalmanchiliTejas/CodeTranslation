#include <iostream>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  int count = 0;
  bool flag = true;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++) {
      char a;
      cin >> a;
      if (a == '#'){
        if (count == j) count++;
        else flag = false;
      }
    }
    count--;
  }
  
  if (flag == true) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}