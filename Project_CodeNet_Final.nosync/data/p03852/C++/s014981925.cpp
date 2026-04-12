#include <bits/stdc++.h>
using namespace std;

bool contain(string &str, char c) {
  return str.find(c) != string::npos;
}

int main() {
  char c;
  cin >> c;
  string vowel = "aeiou";
  cout << (contain(vowel, c) ? "vowel" : "consonant") << endl;
}
