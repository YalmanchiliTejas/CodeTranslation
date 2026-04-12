#include <iostream>
#include <math.h>
using namespace std;
int main() {
  float n;
  int x, y;
  cin >> n;
  x = n * 800;
  y = 200 * floor(n / 15);
  cout << x-y << endl;
}
