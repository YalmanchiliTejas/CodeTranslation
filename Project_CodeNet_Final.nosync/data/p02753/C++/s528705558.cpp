#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  string str;
  vector<int> stations(3, 0);

  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'A') {
      stations[0]++;
    } else {
      stations[1]++;
    }
  }

  if (stations[0] > 0 && stations[1] > 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}