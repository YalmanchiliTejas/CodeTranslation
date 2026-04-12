#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  cout << ((s[0] == s[1] && s[1] == s[2] && s[0] == s[2]) ? "No" : "Yes") << endl;
  return 0;
}