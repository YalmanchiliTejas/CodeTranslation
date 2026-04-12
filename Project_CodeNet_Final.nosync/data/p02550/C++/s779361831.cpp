/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], f[N], b[N];

void solve() {
	int n, x, m;
	cin >> n >> x >> m;
	f[x] = 1;
	a[0] = 0;
	b[0] = x;
	int num = 0, s = 0;
	while (true) {
		num++;
	//	cout << a[num] << endl;
		x = ((x * x) % m);
		b[num] = x;
		if (f[x]) {
			s = f[x];
			break;
		}
		f[x] = num + 1;
	}
	s--;
	num--;
	int ans = 0;
	for (int i = 0; i < s; i++)
		ans += b[i];
	a[s] = 0;
	for (int i = s; i <= num; i++) {
		a[i + 1] = a[i] + b[i];
	}
	if (n <= num) {
		ans = 0;
		for (int i = 0; i < n; i++)
			ans += b[i];
		cout << ans;
		return;
	}
	n -= s;
	int t = (num - s + 1);
	ans += (n / t) * a[num + 1];
	ans += a[(n % t) + s];
	cout << ans;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}
