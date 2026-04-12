#include <iostream>
using namespace std;

int main() {
  int x, y, z; cin >> x >> y >> z;
  cout << (x < z ? 0 : (x-z) / (y+z)) << endl;
}