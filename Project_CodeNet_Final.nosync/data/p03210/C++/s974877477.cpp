#include <iostream>
#include <cmath>

using namespace std;

int main() {
  long x;
  cin >> x;
  auto ans = x==3||x==5||x==7 ? "YES" : "NO";
  cout << ans << endl;
  return 0;
}
