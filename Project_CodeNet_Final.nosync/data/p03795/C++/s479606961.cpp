#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int x = 800 * n, y = 200*(n/15);
  cout << x - y << endl;
  return 0;
}
