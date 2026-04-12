#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  string S;
  cin >> S;
  for (int i = 0; i < S.size() - 1; i++) {
    if (S.substr(i, 2) == "AC") {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
