#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  vector<tuple<ll,ll>> vp;
  ll mxmn = 0;
  ll mnmx = 1e9+1;
  ll mn = 1e9+1;
  ll mx = 0;
  REP(i,n) {
    ll x,y;
    cin>>x>>y;
    if (x > y) swap(x, y);
    mxmn = max(mxmn, x);
    mnmx = min(mnmx, y);
    mn = min(mn, x);
    mx = max(mx, y);
    vp.emplace_back(x, y);
  }
  ll ans = (mx - mnmx) * (mxmn - mn);
  sort(ALL(vp));
  REP(i,n) {
    ll x,y;
    tie(x,y) = vp[i];
    ans = min(ans, (mx - mn) * (mxmn - min(mnmx, x)));
    mxmn = max(mxmn, y);
    if (x > mnmx) break;
  }
  cout << ans << endl;
  return 0;
}
