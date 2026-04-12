#include <iostream>
using namespace std;

int main() {
  while (1) {
    int m = -1;
    int mi = -1;
    for (int i = 0; i < 5; ++i) {
      int a, b, c;
      cin >> a >> b;
      if (!a && !b) {
        return 0;
      }
      c = a + b;
      if (m < c) {
        m = c;
        mi = i;
      }
    }
    cout << (char)('A' + mi) << " " << m << endl;
  }
}