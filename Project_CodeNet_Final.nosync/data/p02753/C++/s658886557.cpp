#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int a = 0;
  int b = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a++;
    } else if (s[i] == 'B') {
      b++;
    }
  }
  if ((a == s.size()) || (b == s.size())) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }

  return 0;
}
