#include <iostream>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool a = false, b = false;
  for (auto c : s) {
    if (c == 'A') {
      a = true;
    }
    if (c == 'B') {
      b = true;
    }
  }

  if (a && b) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}