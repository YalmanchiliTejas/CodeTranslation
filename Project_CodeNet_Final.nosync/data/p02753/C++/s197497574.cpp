#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
//ll n;
//ld ;
string s;
// char c;

int main() {
  cin >> s;
  bool ans = (s[0]!=s[1]) || (s[1]!=s[2]) || (s[1]!=s[2]);
  yorn(ans);
  return 0;
}