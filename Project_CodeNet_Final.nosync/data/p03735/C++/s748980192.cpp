#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

P p[200000];
signed main() {
	int n; scanf("%d", &n);
	ll Min = LLONG_MAX, Max = LLONG_MIN;
	rep(i, n) {
		scanf("%lld%lld", &p[i].first, &p[i].second);
		if (p[i].first > p[i].second)swap(p[i].first, p[i].second);
	}
	sort(p, p + n);
	//MaxとMinが同じところに入らない
	ll a = INT_MAX, b = 0, c = INT_MAX, d = 0;
	rep(i, n) {
		a = min(a, p[i].first); b = max(a, p[i].first);
		c = min(c, p[i].second); d = max(d, p[i].second);
	}
	ll ans = (b - a)*(d - c);
	//MaxとMinが同じところに入る
	multiset<ll>k, t;
	rep(i, n) {
		k.insert(p[i].first);
		t.insert(p[i].second);
	}
	rep(i, n) {
		ans = min(ans, (*k.rbegin() - *k.begin())*(*t.rbegin() - *t.begin()));
		k.erase(k.find(p[i].first)); t.erase(t.find(p[i].second));
		k.insert(p[i].second); t.insert(p[i].first);
	}
	ans = min(ans, (*k.rbegin() - *k.begin())*(*t.rbegin() - *t.begin()));
	printf("%lld\n", ans);
}