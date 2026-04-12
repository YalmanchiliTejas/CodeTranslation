#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  string result;
  if (s[0] == s[1] && s[1] == s[2]) {
    result = "No";
  } else {
    result = "Yes";
  }
  cout << result << endl;
  return 0;
}