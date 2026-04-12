#include <iostream>
using namespace std;

int main(){
  int x, y, z, ans=0;
  cin >> x >> y >> z;
  ans = (x-z)/(y+z);
  cout << ans << endl;
  return 0;
}
