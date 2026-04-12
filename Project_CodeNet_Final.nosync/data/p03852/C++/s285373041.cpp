#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i)


int main() {
  string s = "aiueo";
  char c;
  cin >> c;
  string ans = "consonant";
  if(s.find(c) != string::npos) ans = "vowel";
    
  cout << ans << endl;  
  return 0;
  
}