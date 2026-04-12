#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define rep(i, n) FOR(i, 0, n)

int main() {
  char c;cin>>c;
  string vowel = "aeiou";
  bool ans = false;
  rep(i,5) if(vowel[i]==c) ans=true;
  cout << (ans?"vowel":"consonant") << endl;
}
