#include <iostream>
#include <string>
using namespace std;

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  int n = 100 * a + 10 * b + c;
  if (n % 4 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}