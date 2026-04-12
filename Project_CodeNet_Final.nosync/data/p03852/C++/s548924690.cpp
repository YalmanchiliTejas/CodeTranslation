#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  const char* result = "consonant";
  if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) {
    result = "vowel";
  }
  cout << result << endl;
  return 0;
}
