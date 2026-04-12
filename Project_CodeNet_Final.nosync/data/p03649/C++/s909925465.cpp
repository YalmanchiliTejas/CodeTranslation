#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = numeric_limits<int>::max() / 2;
const int NEG_INF = numeric_limits<int>::min() / 2;
const int MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.rbegin(), a.rend());
	ll res = 0;
	while (true) {
		bool flag = true;
		ll sousa = 0;
		vector<ll> minus(n, 0);
		for (int i = 0; i < n; i++) {
			if (a[i] < n) continue;
			ll tmp = 0;
			tmp = (a[i] - n) / n + 1;
			a[i] -= tmp*n;
			//cout << tmp << endl;
			sousa += tmp;
			res += tmp;
			minus[i] = tmp;
		}
		for (int i = 0; i < n; i++) {
			a[i] += (sousa-minus[i]);
			if (a[i] >= n) flag = false;
		}
		if (flag) break;
	}
	cout << res << endl;
}
