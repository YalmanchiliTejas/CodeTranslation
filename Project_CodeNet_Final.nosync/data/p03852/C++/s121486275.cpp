#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.at(0) == 'a' || s.at(0) == 'i' || s.at(0) == 'u'|| s.at(0) == 'e'|| s.at(0) == 'o') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}
