#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 800 * n - 200 * (n / 15);
  cout << ans << endl;
}
