#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char c;
  string result;

  cin >> c;
  (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')? result="vowel" : result="consonant";
  cout << result << endl;
}