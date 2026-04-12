#include <iostream>

using namespace std;

int main(void) {
  int x, y, z;
  cin >> x >> y >> z;

  for(int i = 1; ; i++) {
    if(x < z * (i + 1) + y * i) {
      cout << i - 1 << endl;
      return 0;
    }
  }
}