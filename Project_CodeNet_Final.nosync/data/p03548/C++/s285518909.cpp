#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  double X, Y, Z;
  cin >> X >> Y >> Z;

  // 最初に左端を切り捨てる
  // あとは Y + Z で割る
  int ans = (X - Z) / (Y + Z);

  cout << ans << endl;

  return 0;
}
