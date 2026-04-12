#include <bits/stdc++.h>
using namespace std;
// 居合を終え、青い絵を覆う
int main() {
  char c;
  cin >> c;

  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    cout << "vowel" << endl;
  } else { 
    cout << "consonant" << endl;
  }

  return 0;
}