#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,ans;
  
  cin >> S;
  if (S[0] == S[1] && S[1] == S[2]) {
    ans = "No";
  } else {
    ans = "Yes";
  }
  cout << ans << endl;
}