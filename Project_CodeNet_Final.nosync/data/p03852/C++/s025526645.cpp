#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0, max_i = (n); i < max_i; i++)
#define repi(i, a, b) for (long long i = (a), max_i = (b); i < max_i; i++)
using namespace std;
typedef long long ll;

bool isVowel(char c) {
  string S = "aeiou";
  bool b = false;
  rep(i,S.size()) if(c==S[i]) b = true; 
  return b;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  char c; cin >> c;
  if(isVowel(c)) puts("vowel");
  else puts("consonant");

  return 0;
}
