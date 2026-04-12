#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  bool hasVowel = false;
  cin >> c;
  string vowel = "aiueo";
  for (int i=0; i<5; i++) {
	if (c == vowel.at(i)) hasVowel = true;
  }
  if (hasVowel == true) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}
  
  