#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> e(12);
  int i;
  for (i = 0; i < e.size(); i++) {
    cin >> e[i];
  }
  sort(e.begin(), e.end());
  for (i = 0; i < 3; i++) {
    if (!(e[4 * i + 0] == e[4 * i + 1] && e[4 * i + 2] == e[4 * i + 3] && e[4 * i + 0] == e[4 * i + 3])) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}

