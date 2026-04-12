#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  if (s == "a" or s == "e" or s == "i" or s == "o" or s == "u") {
    cout << "vowel" << endl;
  }
  else {
    cout << "consonant" << endl;
  }
}