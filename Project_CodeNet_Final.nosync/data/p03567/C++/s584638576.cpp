#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, ans = "No";
  cin >> S;
  for (int i = 0; i < S.size() - 1; i++) {
    if (S.at(i) == 'A' && S.at(i + 1) == 'C') {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
}