#include <bits/stdc++.h>
#define rep(i, s, e) for(int i = s; i < e; i++)
#define rrep(i, s, e) for(int i = s; i > (s)-(e); i--)
#define pr(s) std::cout << s << std::endl
#define prb(s) std::cout << s
using namespace std;



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);


  string s;
  cin >> s;

  if (s == "a" || s == "e" || s == "i" || s == "o" || s == "u") pr("vowel");
  else pr("consonant");


  return 0;
}
