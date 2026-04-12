#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;

  string vowels = "aeiou";
  cout << (vowels.find(c) == string::npos ? "consonant" : "vowel") << endl;
}
