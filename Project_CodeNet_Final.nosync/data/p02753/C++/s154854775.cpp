#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  string S = "";
  cin >> S;
  string ans = "";
  if(S[0] == S[1] && S[1] == S[2]) {
    ans = "No";
  }
  else {
    ans = "Yes";
  }

  cout << ans << endl;

  return 0;
}
