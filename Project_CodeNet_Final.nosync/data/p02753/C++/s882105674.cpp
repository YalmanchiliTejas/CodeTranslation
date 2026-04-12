#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  string S; cin >> S;
  string result = "Yes";

  if (S[0] == S[1] && S[1] == S[2]) result = "No";

  cout << result << endl;
  return 0;
}