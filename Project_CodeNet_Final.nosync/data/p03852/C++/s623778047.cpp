#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string c;

  cin >> c;

  if ("aeiou"s.find(c) == string::npos) {
    cout << "consonant" << endl;
  } else {
    cout << "vowel" << endl;
  }
}
