#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int num = 100 * r + 10 * g + b;

  if (num % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
