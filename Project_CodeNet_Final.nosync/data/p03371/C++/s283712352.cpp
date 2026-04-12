#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll x, y;
  cin >> x >> y;
  ll z = min(x, y);
  ll ans = 0;
  ans = z * min( a + b, 2 * c);
  if (x - z > 0) {
    ans += (x-z) * min(a, 2*c);
  }
  if (y - z > 0) {
    ans += (y-z) * min(b, 2*c);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}