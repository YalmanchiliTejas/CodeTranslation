#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e19;

int main()
{
	int N;
	cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll add = 0;
	for (int i = N - 1; i >= 1; i--) {
		if (a[i] > a[0] + N) {
			ll v = (a[i] - a[0]) / (N + 1);
			add += v;
			a[i] -= v * (N + 1);
		}
	}
	sort(a.rbegin(), a.rend());
	ll id = 0;
	ll mi = INF;
	for (int i = 0; i < N; i++) {
		a[i] += add + i;
		if (a[i] <= N - 1) {
			cout << add + i << endl;
			return 0;
		}
		if (a[i] < mi) {
			mi = a[i];
			id = i;
		}
	}
	cout << ((mi - (N - 1)) * N + id + add) << endl;
	return 0;
}
