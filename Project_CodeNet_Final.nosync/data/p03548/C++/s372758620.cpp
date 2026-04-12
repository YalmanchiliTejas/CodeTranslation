#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int x, y, z;
  int cnt = 0;
  cin >> x >> y >> z;
  while (true) {
    x -= y + z;
    if (x - z < 0) break;
    cnt++;
  }
  cout << cnt << endl;
}