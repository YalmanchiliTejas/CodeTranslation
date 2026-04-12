#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll, ll> Pll;
typedef pair<int, Pii > P1;

#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define mp1(a,b,c) P1(a,P(b,c))
#define get_arsize(a) (sizeof(a)/sizeof(a[0]))

const ll MOD = 1000000007;
const double EPS = 1e-10;
const int MAX = 200000;

int main() {
  ll n;
  cin >> n;
  vector<ll> a;
  rep (i, n) {
    ll t;
    cin >> t;
    a.push_back(t);
  }
  ll ans = 0;
  vector<ll> sum;
  for (int j = 0; j < n; ++j) {
    sum.push_back(a[j]);
    if (j > 0) {
      sum[j] = (sum[j-1] + a[j]);
      sum[j] %= MOD;
    }
  }
  for (int i = 1; i < n; ++i) {
    ll tmp = sum[i-1] * a[i];
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
