#include <iostream>
using namespace std;
int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((b * 10 + c) % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}