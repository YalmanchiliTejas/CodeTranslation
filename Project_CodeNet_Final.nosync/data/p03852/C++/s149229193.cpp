#include <bits/stdc++.h>
using namespace std;

int main() {
  char S;
  cin >> S;
  string ans;
  if (S == 'a'|S == 'e'||S == 'i'||S == 'o'||S == 'u') ans = "vowel";
  else ans = "consonant"; 
  cout << ans << endl;
}
