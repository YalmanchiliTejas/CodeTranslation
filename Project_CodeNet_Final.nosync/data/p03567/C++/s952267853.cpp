#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  string ans = "No";
  for (int i = 0; i < str.size()-1; i++) {
    if (str.at(i) == 'A') {
      if (str.at(i+1) == 'C') {
        ans = "Yes";
      }
    }
  }
  cout << ans << endl;
}