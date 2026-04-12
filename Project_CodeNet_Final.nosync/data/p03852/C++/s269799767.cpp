#include <bits/stdc++.h>
using namespace std;

int main() {
  string A;
  cin >> A;
  vector<string> str = {"a", "e", "i", "o", "u"};
  bool x = false;
  for (string n : str) {
    if (A == n) {
      x = true;
    }
  }
  if (x) {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}
