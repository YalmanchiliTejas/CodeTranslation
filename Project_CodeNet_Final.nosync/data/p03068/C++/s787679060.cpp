#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n;
  cin >> s;
  cin >> k;
  k--;
  for (char c : s) {
    if (c == s[k]) {
      cout << c;
    } else {
      cout << "*";
    }
  }
  cout << endl;
  return 0;
}
