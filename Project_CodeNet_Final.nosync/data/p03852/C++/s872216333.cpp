#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  string flag;
  cin >> c;
  flag = "consonant";
  if (c == 'a' || c == 'i') {
    flag = "vowel";
  }
  if (c == 'u' || c == 'e') {
    flag = "vowel";
  }
  if (c == 'o') {
    flag = "vowel";
  }
  
  cout << flag << endl;
}
