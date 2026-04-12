#include <iostream>
using namespace std;

int main() {
  int _, g, b;
  cin >> _ >> g >> b;

  bool ng = ((g*10) + b) % 4;

  if (!ng) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
