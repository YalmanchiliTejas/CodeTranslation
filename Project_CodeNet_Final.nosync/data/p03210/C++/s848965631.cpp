#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int main() {

  int X;
  cin >> X;

  string ans = (X==7 or X==5 or X==3) ? "YES" : "NO";

  cout << ans << endl;

  return 0;
}