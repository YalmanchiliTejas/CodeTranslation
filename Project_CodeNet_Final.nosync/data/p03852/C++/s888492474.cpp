#include <bits/stdc++.h>
using namespace std;

int main()
{
  char c;
  cin >> c;
  bool ans = false;
  if(c == 'a') ans = true;
  if(c == 'i') ans = true;
  if(c == 'u') ans = true;
  if(c == 'e') ans = true;
  if(c == 'o') ans = true;
  
  if(ans) cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}
