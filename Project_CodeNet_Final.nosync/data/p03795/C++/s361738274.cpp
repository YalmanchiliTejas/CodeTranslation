#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define rep(i, n) FOR(i, 0, n)

int main() {
  int n;cin>>n;
  int x=n*800;
  int y=n/15*200;
  int ans = x-y;
  // cout << (ans?"H":"D") << endl;
  cout << ans << endl;
}
