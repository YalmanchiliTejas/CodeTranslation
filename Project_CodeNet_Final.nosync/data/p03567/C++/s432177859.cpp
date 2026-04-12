#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans = "No";
  for (int i=1; i<S.size(); i++) if (S[i-1] == 'A' && S[i] == 'C') {ans = "Yes"; break;}
  cout << ans << endl;
  return 0;
}
