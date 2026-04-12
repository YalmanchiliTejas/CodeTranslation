#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	ll ans = 0;
	while (1) {
		ll s = 0;
		for (int i = 0; i < N; i++) {
			s += a[i] / N;
		}
		ans += s;
		if (s == 0) break;
		for (int i = 0; i < N; i++) {
			a[i] += s - (a[i] / N)*(N + 1);
		}
	}
	cout << ans << endl;
 }