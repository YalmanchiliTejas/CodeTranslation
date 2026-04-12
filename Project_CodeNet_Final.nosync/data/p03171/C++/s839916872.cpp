#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll, ll>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c, i) ((c).find(i) != end(c))
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define FORD(i,a,b) for (ll i=ll(b)-1; i >= a; i--)

ll n;
vl a;
vector<vector<pair<bool, ll>>> dp;

ll compute(ll start, ll count, ll turn) {
  if(dp[start][count].xx)
    return dp[start][count].yy;

  if(count == 0) {
    dp[start][0] = mp(true, a[start]*(turn%2?-1:1));
    return dp[start][0].yy;
  }


  ll val1 = compute(start+1, count-1, turn + 1) + (turn%2?-1:1)*a[start];
  ll val2 = compute(start, count-1, turn + 1) + (turn%2?-1:1)*a[start + count];


  dp[start][count] = mp(true, (turn%2?min(val1, val2): max(val1, val2)));
  return dp[start][count].yy;
}

int main() {
  cout << fixed << setprecision(8);
  cin >> n;
  FOR(i,0,n) {
    ll x;
    cin >> x;
    a.pb(x);
  }

  dp.assign(n, vector<pair<bool, ll>>(n, mp(false, -1)));

  cout << compute(0, n-1, 0) << endl;
}
