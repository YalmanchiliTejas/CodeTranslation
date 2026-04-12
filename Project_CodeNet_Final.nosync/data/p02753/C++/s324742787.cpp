#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  string ans = "Yes";
  if (s[0] == s[1] && s[1] == s[2]) ans = "No";
  cout << ans << endl;
  return 0;
}
