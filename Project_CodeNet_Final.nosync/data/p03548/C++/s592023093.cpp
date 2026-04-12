#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int x,y,z;
  cin >> x >> y >> z;
  int ans = 0;
  int id  = 0;
  if(x >= y + 2 * z) {
    ans++;
    id = y + 2 * z;
  }
  while(1) {
    if(id + y + z > x) break;
    id += y + z;
    ans++;
  }
  cout << ans << endl;
}
