#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;


int main(void) {
  int n;
  cin >> n;
  vector<int> v;
  
  rep(i, 0, n) {
    int a;
    cin >> a;
    int l = -1, r = sz(v);
    while (r-l>1) {
      int m = (l+r)/2;
      if (v[m]>=a) l = m;
      else r = m;
    }
    if (r==sz(v)) v.pb(a);
    else v[r] = a;
  
  }
  
  int ans = sz(v);

  cout << ans << endl;

    return 0;
}

