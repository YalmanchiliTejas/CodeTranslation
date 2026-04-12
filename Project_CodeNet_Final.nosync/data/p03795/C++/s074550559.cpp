
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int x = n * 800;
  int y = n / 15 * 200;
  cout << x - y << endl;
  return 0;
}
