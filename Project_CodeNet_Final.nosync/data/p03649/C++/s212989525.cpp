#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair

const int N = 60;
const ll INF = 1e18;
ll a[N];
ll q[N];
ll r[N];
ll tmp[N];
ll k = 0;

int main() {
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);	
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q[i] = a[i] / (n + 1);
		r[i] = a[i] % (n + 1);
	}
	while (true) {
		for (int i = 0; i < n; i++)
			tmp[i] = q[i];
		sort(tmp, tmp + n);
		ll m1 = tmp[n - 1];
		ll m2 = -INF;
		ll t = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (tmp[i] == m1)
				t = n - i;
			else {
				m2 = tmp[i];
				break;
			}
		}
		ll sub = min(m1 - m2, (m1 * (n + 1) + k - n) / (n + 1 - t) - 2);
		if (sub < 0)
			break;
		for (int i = 0; i < n; i++) {
			if (q[i] == m1)
				q[i] -= sub;
		}
		k += sub * t;
		if (sub != m1 - m2)
			break;
	}
	for (int i = 0; i < n; i++)
		a[i] = q[i] * (n + 1) + r[i] + k;
	while (true) {
		ll m = -INF;
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > m) {
				m = a[i];
				cur = i;
			}
		}
		if (m <= n - 1) {
			cout << k << endl;
			return 0;
		}
		for (int i = 0; i < n; i++)
			a[i]++;
		a[cur] -= n + 1;
		k++;
	}
	throw;
	return 0;
}
