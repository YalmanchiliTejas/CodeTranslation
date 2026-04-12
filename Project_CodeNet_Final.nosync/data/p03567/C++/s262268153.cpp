#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "No";

  for (int i = 0; i < s.size() - 1; ++i) {
    if (s[i] == 'A' && s[i + 1] == 'C') {
      ans = "Yes";
    }
  }

  cout << ans << endl;
}
