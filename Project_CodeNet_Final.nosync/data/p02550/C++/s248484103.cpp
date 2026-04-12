#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void Yes() {cout << "Yes\n";}
void No() {cout << "No\n";}
void YES() {cout << "YES\n";}
void NO() {cout << "NO\n";}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n; int x, m;
	cin >> n >> x >> m;
	if (n == 1) {
		cout << x << endl;
		return 0;
	}

	vector<bool> v(m, false);
	v[x] = true;
	ll ans = x;
	deque<ll> dq;
	dq.push_back(x);
	for (int i = 1; i < n; i++) {
		ll a = dq.back() * dq.back() % m;
		if (v[a]) {
			n -= dq.size();
			while (dq.front() != a) dq.pop_front();
			break;
		} else {
			ans += a;
			dq.push_back(a);
			v[a] = true;
		}
		if (i == n - 1) {
			cout << ans << endl;
			return 0;
		}
	}

	ll sz = dq.size();
	vector<ll> sum(sz + 1, 0);
	for (int i = 0; i < sz; i++) sum[i + 1] = sum[i] + dq[i];
	cout << ans + sum[sz] * (n / sz) + sum[n % sz] << endl;

	return 0;
}