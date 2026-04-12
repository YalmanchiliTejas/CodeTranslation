/// problem link: http://lightoj.com/volume_showproblem.php?problem=1031
/// topic: dp
#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);

#define dbg1(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;


ll dp[3005][3005];
ll a[3005];

ll calc(ll l, ll r)
{
  if (l > r) return 0;
  ll &ret = dp[l][r];
  if (ret != -1) return ret;

  ll sm = 0;
  ll dif = -1e18;
  //for (ll i = l; i <= r; i++) {
  sm += a[l];
  dif = max(dif, sm - calc(l + 1, r));
  //}
  sm = 0;
  //for (ll i = r; i >= l; i--) {
  sm += a[r];
  dif = max(dif, sm - calc(l, r - 1));
  //}
  return ret = dif;
}

int main()
{
  // FASTIO
  /*
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif
  //*/
  ll T;
  //scanf("%d", &T);
  T = 1;
  for (ll cs = 1; cs <= T; cs++) {
    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", calc(0, n - 1ll));
  }
  return 0;
}