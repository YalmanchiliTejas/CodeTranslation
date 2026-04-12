#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const ll INF = (ll)(1e18);

int main(void){
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = INF;
  ll m = max(x, y);
  REP(i, m+1){
    ll t = 2*c*i;
    if(x-i > 0) t += a*(x-i);
    if(y-i > 0) t += b*(y-i);
    chmin(ans, t);
  }
  cout << ans << endl;
  return 0;
}