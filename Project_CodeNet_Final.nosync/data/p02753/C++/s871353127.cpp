#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string station;
  cin >> station;

  int res = 0;
  if (station[0] != station[1]) {
    res += 1;
  }
  if (station[1] != station[2]) {
    res += 1;
  }

  cout << ((res > 0) ? "Yes" : "No") << endl;

  return 0;
}