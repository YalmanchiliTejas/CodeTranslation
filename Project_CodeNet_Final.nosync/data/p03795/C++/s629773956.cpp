#include <iostream>
using namespace std;
int main() {
  int x, y, z;
  cin >> x;
  y = x * 800;
  for(int i = 15; i <= x; i += 15) {
    z += 200;
  }
  cout << y - z << endl;
}