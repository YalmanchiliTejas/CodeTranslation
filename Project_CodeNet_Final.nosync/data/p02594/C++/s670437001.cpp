#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x; cin >> x;
  string ans = "No";
  if (x >= 30) ans = "Yes";
  cout << ans << endl;
  return 0;
}