#include <bits/stdc++.h>
using namespace std;

int main() {
  char a;
  cin >> a;
  string ans = "consonant";
  if (a == 'a') {
    ans = "vowel";
  } else if (a == 'i') {
    ans = "vowel";
  } else if (a == 'u') {
    ans = "vowel";
  } else if (a == 'e') {
    ans = "vowel";
  } else if (a == 'o') {
    ans = "vowel";
  }
  cout << ans << endl;
}