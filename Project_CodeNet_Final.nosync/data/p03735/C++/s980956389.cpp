//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

ll x[200010], y[200010];
signed main(void)
{
	ll n;
	cin >> n;
	ll rmi = INF, rma = -1, bmi = INF, bma = -1;
	vector<pair<ll, ll>> xy;
	REP(i, n) {
		cin >> x[i] >> y[i];
		if(x[i] > y[i]) swap(x[i], y[i]);
		xy.emplace_back(x[i], i);
		rmi = min(rmi, x[i]);
		bmi = min(bmi, y[i]);
		rma = max(rma, x[i]);
		bma = max(bma, y[i]);
	}

	ll ans = (rma-rmi)*(bma-bmi);
	sort(ALL(xy));
	ll xymax = y[xy.front().second], xymin = y[xy.front().second],
		 d = xy.back().first - xy.front().first;
	REP(i, n) {
		d = min(d, max(xymax, xy.back().first) - min(xymin, xy[i].first));
		xymax = max(xymax, y[xy[i].second]);
		xymin = min(xymin, y[xy[i].second]);
	}
	d = min(d, xymax-xymin);
	rma = bma;
	ans = min(ans, (rma - rmi) * d);
	cout << ans << endl;
	return 0;
}
