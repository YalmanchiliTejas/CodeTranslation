#include <iostream>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  
  int len = Z, ans = 0;
  while (len < X) {
    len += Y + Z;
    ans++;
  }
  if (len > X) ans--;
  
  cout << ans << endl;
  
  return 0;
}