#include <bits/stdc++.h>
using namespace std;


int main() {
  char c;
  cin >> c;
  
  string ans="consonant";
  if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ans="vowel";
  
  cout << ans << endl;

  return 0;
}
