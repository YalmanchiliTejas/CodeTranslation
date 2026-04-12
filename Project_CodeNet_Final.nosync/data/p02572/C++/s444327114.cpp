#include<bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int s = 0;
	for(int i = 1; i < n; i++) (s += a[i]) %= m;
	int res = 0;
	for(int i = 0; i < n - 1; i++) {
		(res += 1LL * s * a[i] % m) %= m;
		(s += m - a[i + 1]) %= m;
	}
	cout << res << '\n';
}
