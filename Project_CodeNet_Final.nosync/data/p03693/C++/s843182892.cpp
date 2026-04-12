#include <iostream>
using namespace std;

int main(void) {
  int R, G, B;
  cin >> R >> G >> B;
  cout << ((R * 100 + G * 10 + B) % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}
