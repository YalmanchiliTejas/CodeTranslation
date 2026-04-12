#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  char bo[] = {'a', 'i', 'u', 'e', 'o'};
  for (int i = 0; i < 5; i++) {
    if (c == bo[i]) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}
