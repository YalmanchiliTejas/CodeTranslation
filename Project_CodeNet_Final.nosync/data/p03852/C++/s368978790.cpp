#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  string S;

  cin >> c;

  if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o') {
      S="vowel";
  } else {
      S="consonant";
  }
  
  cout << S << endl;
}
