#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  string vowels = "aeiou";
  if (vowels.find(c) == string::npos) {
    cout << "consonant" << endl;
  } else {
    cout << "vowel" << endl;
  }
}