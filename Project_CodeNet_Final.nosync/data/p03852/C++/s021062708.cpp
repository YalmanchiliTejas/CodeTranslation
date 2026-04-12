#include <bits/stdc++.h>

using namespace std;

int main() {
  char c;
  cin >> c;
  unordered_set<char> S = {'a', 'e', 'i', 'o', 'u'};
  if (S.count(c)) {
    cout << "vowel";
  } else {
    cout << "consonant";
  }
  return 0;
}
