#include <bits/stdc++.h>
using namespace std;

int main() {
  char a;
  cin >> a;
  if (('a' == a)or('i' == a)or('u' == a)or('e' == a)or('o' == a)) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
  return 0;
}
