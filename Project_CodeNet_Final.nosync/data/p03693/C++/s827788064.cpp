#include <iostream>
using namespace std;

int main() {
  int x, y, z, a;
  cin >> x >> y >> z;
  a = x * 100 + y * 10 + z;
  if(a % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}