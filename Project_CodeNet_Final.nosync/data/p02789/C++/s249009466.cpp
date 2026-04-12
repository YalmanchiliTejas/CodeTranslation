#include <iostream>

using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  const char* s = m == n ? "Yes" : "No";
  cout << s << endl;
  return 0;
}
