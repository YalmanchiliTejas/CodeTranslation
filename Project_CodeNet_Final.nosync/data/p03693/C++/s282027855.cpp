#include <iostream>
using namespace std;

int main(void) {
  int r, g, b;
  cin >> r >> g >> b;
  int x = r * 100 + g * 10 + b;
  if(x % 4) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
