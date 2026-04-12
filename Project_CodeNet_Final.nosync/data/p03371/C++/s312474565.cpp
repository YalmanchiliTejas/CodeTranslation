#include <iostream>
#include <string>
#include <cmath> //これはlogを使うときに必要
#include <vector> //これは配列(vector)を使うときに必要
#include <math.h> //べき乗を使うときに必要
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int small = min(x,y);
  int big = max(x,y);
  int money;

  //3通りの算出法
  int p = a * x + b * y;
  int q = c * 2 * small + a * (x - small) + b * (y - small);
  int r = c * 2 * big;
  money = min(min(p,q),r);
  cout << money << endl;
  return 0;
}
