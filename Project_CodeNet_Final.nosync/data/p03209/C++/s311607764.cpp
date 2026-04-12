#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
#define FOR(i, a, b) for(int i = 0; i < (a); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).end()
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
//#define int long long int
const int MOD = 1000000007;
const ll LINF = (ll)1e18 - 1;
const int INF = 1e9 - 1;
const double EPS = 0.000000001;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print(const vector<int> &v) {
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}
VL a(70, 1), p(70, 1);
ll solve(ll n, ll k) {
  if(n == 0) return k <= 0 ? 0 : 1;
  else if(k <= 1 + a[n-1]) return solve(n-1, k-1);
  else return p[n-1] + 1 + solve(n-1, k-2-a[n-1]);
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  ll x;
  cin >> n >> x;
  rep(i, 60) {
    a[i+1] = 2 * a[i] + 3;
    p[i+1] = 2 * p[i] + 1;
  }
  ll ans = solve(n, x);
  out(ans);
  return 0;
}
