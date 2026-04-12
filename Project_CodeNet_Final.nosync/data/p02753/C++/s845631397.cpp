#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;
  int t = count(s.begin(), s.end(), 'A');
  cout << (t == 0 or t == s.size() ? "No" : "Yes");

  return 0;
}