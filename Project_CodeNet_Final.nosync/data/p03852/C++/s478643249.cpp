#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  
  string s = "consonant";
  if(c == 'a') s = "vowel";
  if(c == 'e') s = "vowel";
  if(c == 'i') s = "vowel";
  if(c == 'o') s = "vowel";
  if(c == 'u') s = "vowel";
  
  cout << s << endl;
}