#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int a, b, c;
int main() {
  cin >> a >> b >> c;
  if ((b * 10 + c) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
