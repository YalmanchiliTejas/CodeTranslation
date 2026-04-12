#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using vb = vector<bool>;
using boolGraph = vector<vb>;
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

  int ans = a*x + b*y;
  int tmp;

  if (x < y) tmp = min(c*x*2 + b*(y-x), c*y*2);
  else tmp = min(c*y*2 + a*(x-y), c*x*2);

  ans = min(ans, tmp);
  cout << ans << endl;
  return 0;
}
