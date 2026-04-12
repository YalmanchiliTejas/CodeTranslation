#include <bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
  vector<char> s(3);
  rep(i,3) cin >> s[i];
  int a = 0;
  int b = 0;
  rep(i,3) {
    if (s[i] == 'A') a++;
    if (s[i] == 'B') b++;
  }
  string ans;
  if (a > 0 && b > 0) {
    ans = "Yes";
  } else {
    ans = "No";
  }
  cout << ans << endl;
  return 0;
}
