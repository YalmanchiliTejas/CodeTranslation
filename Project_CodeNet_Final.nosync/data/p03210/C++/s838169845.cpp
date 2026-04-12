#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define PI 3.14159265359
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int X;
  cin >> X;

  if (X == 3 || X == 5 || X == 7)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
