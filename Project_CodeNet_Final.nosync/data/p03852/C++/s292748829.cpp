#include <bits/stdc++.h>
using namespace std;
int main () {
  char c;
  cin >> c;
  string ans = "consonant";
  string A = "aiueo";
  for(char a: A) {
    if(a == c) {
      ans = "vowel";
    }
  }
  cout << ans << endl;
  return 0;
}