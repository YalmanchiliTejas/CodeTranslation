#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
  int r, g, b;
  cin >> r >> g >> b;
  if((100 * r + 10 * g + b) % 4 == 0)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;

  return 0;
}
