#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  const string vowel = "aiueo";
  string s = "consonant";
  for (int i = 0; i < vowel.size(); i++) {
  	if (c == vowel.at(i)) {
    	s = "vowel";
    }
  }
  cout << s << endl;
}