#include <bits/stdc++.h>
using namespace std;

int main(){
  char s;
  cin >> s;
  string vowel = "aeiou";
  if(vowel.find(s)==string::npos) cout << "consonant" << endl;
  else cout << "vowel" << endl;
}