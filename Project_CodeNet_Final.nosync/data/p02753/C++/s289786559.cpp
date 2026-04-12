#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  if (all_of(s.begin(), s.end(), [&](char c) { return c == s[0]; })) puts("No");
  else puts("Yes");
}
