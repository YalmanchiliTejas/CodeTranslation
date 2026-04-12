#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cout << #x << ": " << x << ", "
#define debugln(x) cout << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  vector<P> t(n);
  if (n==1) {
    cout << 0 << endl;
    return 0;
  }
  int minx = INT_MAX;
  int maxx = INT_MIN;
  int miny = INT_MAX;
  int maxy = INT_MIN;
  rep(i, n) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    if (x < minx) {
      minx = x;
    }
    if (x > maxx) {
      maxx = x;
    }
    if (y < miny) {
      miny = y;
    }
    if (y > maxy) {
      maxy = y;
    }
    t.at(i) = P(x, y);
  }
  long ans = (ll)(maxx - minx) * (maxy - miny);
  //debug(maxx); debug(minx); debug(maxy); debug(miny); debugln(ans);

  sort(t.begin(), t.end());
  int ma = max(t.at(0).second, t.at(n-1).first);
  int mif = min(t.at(0).second, t.at(n-1).first);
  int tmp = INT_MAX;
  for(int i=0; i<n-1; i++) {
    mif = min(mif, t.at(i).second);
    int mi = min(mif, t.at(i+1).first);
    ma = max(ma, t.at(i).second);
    tmp = min(tmp, ma-mi);    
  }
  ans = min((ll)ans, (ll)tmp * (maxy - minx));
  cout << ans << endl;
}