#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main() {
  char c;
  string ans;
  cin >> c;

  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
    ans = "vowel";
  }
  else{
    ans = "consonant";
  }

cout << ans << endl;
}