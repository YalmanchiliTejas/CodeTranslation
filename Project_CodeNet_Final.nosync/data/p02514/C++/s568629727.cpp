#include <iostream>

using namespace std;

int main() {
  int n0, n1, n2, n3, n4, n5, m0, m1, m2;

  while (true) {
    cin >> n0 >> n1 >> n2 >> n3 >> n4 >> n5;
    if (n0 == 0 && n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0 && n5 == 0)
      break;
    n0 += n3;
    n1 += n4;
    n2 += n5;
    int count = min(min(n0, n1), n2);
    n0 -= count;
    n1 -= count;
    n2 -= count;
    m0 = count + n0 / 3 + n1 / 3 + n2 / 3;
    if (count >= 1)
      m1 = (count - 1) + (n0 + 1) / 3 + (n1 + 1) / 3 + (n2 + 1) / 3;
    else
      m1 = 0;
    if (count >= 2)
      m2 = (count - 2) + (n0 + 2) / 3 + (n1 + 2) / 3 + (n2 + 2) / 3;
    else
      m2 = 0;
    cout << max(max(m0, m1), m2) << endl;
  }
  return 0;
}