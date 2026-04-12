#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  char s1, s2, s3;
  s1 = s[0];
  s2 = s[1];
  s3 = s[2];
  if (s1==s2 && s2 == s3) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
