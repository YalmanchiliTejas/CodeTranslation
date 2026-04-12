#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PX;
typedef pair<ll, ll> PY;
struct ED {
	ll p1;
	ll p2;
	ll cost;
	ED(ll k1, ll k2, ll k3) : p1(k1), p2(k2), cost(k3) {}
};
const int maxlen = 200005;
PX px[maxlen];
PY py[maxlen];
ll fa[maxlen];
vector<ED> edges;

bool cmp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
	return a.first < b.first;
}

bool cmp_(const ED& e1, const ED& e2) {
	return e1.cost < e2.cost;
}

int getf(int i) {
	return i == fa[i] ? i : fa[i] = getf(fa[i]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> px[i].first >> py[i].first;
		px[i].second = py[i].second = i;
		fa[i] = i;
	}
	sort(px + 1, px + 1 + n, cmp);
	sort(py + 1, py + 1 + n, cmp);
	for (int i = 1; i < n; i++) {
		edges.push_back(ED(px[i].second, px[i + 1].second, px[i + 1].first - px[i].first));
		edges.push_back(ED(py[i].second, py[i + 1].second, py[i + 1].first - py[i].first));
	}
	sort(edges.begin(), edges.end(), cmp_);
	ll ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (getf(edges[i].p1) != getf(edges[i].p2)) {
			ans += edges[i].cost;
			fa[getf(edges[i].p1)] = getf(edges[i].p2);
		}
	}
	cout << ans << endl;
}