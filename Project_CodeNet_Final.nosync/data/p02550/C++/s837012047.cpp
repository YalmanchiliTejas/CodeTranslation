#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, x, m; cin >> n >> x >> m;
	vector<ll> visit(m, -1);
	vector<ll> a;
	ll higePlusCycleLength = 0;
	ll higePlusCycleSum = 0;
	while (visit[x] == -1) {
		a.push_back(x);
		visit[x] = higePlusCycleLength;
		higePlusCycleLength++;
		higePlusCycleSum += x;
		x = x * x % m;
	}
	ll cycle = higePlusCycleLength - visit[x];
	ll cycleSum = 0;
	for (int i = visit[x]; i < higePlusCycleLength; i++) {
		cycleSum += a[i];
	}
	ll ans = 0;
	if (n <= higePlusCycleLength) {
		for (int i = 0; i < n; i++) {
			ans += a[i];
		}
	}
	else {
		n -= higePlusCycleLength;
		ans += higePlusCycleSum;
		ans += cycleSum * (n / cycle);
		n %= cycle;
		for (int i = visit[x]; i < visit[x] + n; i++) {
			ans += a[i];
		}
	}
	cout << ans << endl;
    return 0;
}