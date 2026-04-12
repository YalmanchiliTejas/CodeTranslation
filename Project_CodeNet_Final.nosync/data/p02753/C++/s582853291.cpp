#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;

  string ans = "Yes";
  if (s.at(0) == s.at(1) && s.at(1) == s.at(2)) {
    ans = "No";
  }
  cout << ans << endl;
}