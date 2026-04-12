#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/04/29  Problem: ARC 073 C / Link: http://arc073.contest.atcoder.jp/tasks/arc073_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  ll x[200200];
  ll y[200200];
  vector<pll> s;
  FOR(i, 0, N) {
	  cin >> x[i] >> y[i];
	  if (x[i] > y[i])swap(x[i], y[i]);
	  //x<y;
	  s.push_back(mp(x[i], y[i]));
  }
  sort(s.begin(), s.end());

  ll rmin = LINF, bmin = LINF;
  ll rbig = 0, bbig = 0;
  //r min,b max
  FOR(i, 0, N) {
	  rmin = min(rmin, s[i].first);
	  rbig = max(rbig, s[i].first);
	  bmin = min(bmin, s[i].second);
	  bbig = max(bbig, s[i].second);
  }
  ans = (rbig - rmin)*(bbig - bmin);
  //r min r max
  ll ran = (bbig - rmin);
  bmin = s[0].first;
  bbig = s[N-1].first;
  ll bminmin = LINF;
  FOR(i, 0, N - 1) {
	  bmin = s[i + 1].first;
	  bminmin = min(bminmin,s[i].second);
	  bbig = max(bbig, s[i].second);
	  ans = min(ans, ran*(bbig - min(bmin, bminmin)));
  }

  cout << ans << endl;

  return 0;
}
