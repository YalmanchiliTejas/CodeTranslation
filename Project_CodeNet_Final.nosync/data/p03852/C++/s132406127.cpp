#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  char c;
  string V="vowel",C="consonant";
  cin >> c;
  if (c=='a' or c=='i' or c=='u' or c=='e' or c=='o') {
    cout<<V<<endl;
  }
  else {
    cout<<C<<endl;
  }
}


