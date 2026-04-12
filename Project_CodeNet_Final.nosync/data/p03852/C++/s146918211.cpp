#include <bits/stdc++.h>

using namespace std;

int main() {
  char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
  char c;
  cin >> c;
  for (int i = 0; i < 5; ++i) {
    if (vowel[i] == c) {
      cout << "vowel" << endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}

