#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int a;
  cin >> a;
  int x,y;
  x = 800*a;
  y = a/15*200;
  cout << x-y << endl;
  return 0;
}