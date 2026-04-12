//
// tested with : g++ (GCC) 8.3.0
//

#include <iostream>
using namespace std;

int main() {
  int aka, midori, ao;
  cin >> aka >> midori >> ao;
  int line = aka * 100 + midori * 10 + ao;

  if (line % 4 == 0) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}