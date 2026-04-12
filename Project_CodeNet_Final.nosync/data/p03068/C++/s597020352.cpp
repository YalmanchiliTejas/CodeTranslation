#include <iostream>

using namespace std;

int main() {
  int n, k;
  string s, result;

  cin >> n;
  cin >> s;
  cin >> k;

  char repl = s[k-1];
  result = "";

  for (int i = 0; i < n; i++) {
    char k = s[i];
    if (repl != k) {
      result += "*";
    } else {
      result += k;
    }
  }

  cout << result << endl;

  return 0;
}