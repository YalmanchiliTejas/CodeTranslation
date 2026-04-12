#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int n;
pair<ll, ll> p[200005];
ll INF = 1000000000000000000;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll mama = -1, mimi = INF, mami = INF, mima = -1, mai, mii;
	FOR(i, n) {
		ll x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		mimi = min(mimi, x);
		mima = max(mima, x);
		mami = min(mami, y);
		mama = max(mama, y);
		p[i] = make_pair(x, y);
	}
	ll res = (mama-mami) * (mima-mimi);

	sort(p, p+n);

	ll ma = p[n-1].first;
	ll mi = INF, mmi = INF;
	FOR(i, n-1) {
		mi = min(mi, p[i].second);
		mmi = min(mi, p[i+1].first);
		ma = max(ma, p[i].second);
		res = min(res, (mama-mimi)*(ma-min(mi,mmi)));
	}

	cout << res << endl;
	return 0;
}