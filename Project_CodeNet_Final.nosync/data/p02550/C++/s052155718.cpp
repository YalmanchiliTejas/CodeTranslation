#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll n, x, m;
	cin >> n >> x >> m;
	vector<int> a;
	set<int> p;
	int now = x;
	ll ans = 0, sum = 0;
	while (!p.count(now)) {
		a.push_back(now);
		p.insert(now);
		now = now % m * now % m;
	}
	int l = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == now) {
			break;
		}
		l++;
	}
	ll c = (n - l) / (a.size() - l);
	ll r = (n - l) % (a.size() - l);
	for (int i = l; i < a.size(); i++) {
		sum += a[i];
	}
	if (n < l) {
		for (int i = 0; i < n; i++) {
			ans += a[i];
		}
		cout << ans << endl;
		return 0;
	}
	ll lSum = 0;
	for (int i = 0; i < l; i++) {
		lSum += a[i];
	}
	ans = lSum + sum * c;
	for (int i = l; i < l + r; i++) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}