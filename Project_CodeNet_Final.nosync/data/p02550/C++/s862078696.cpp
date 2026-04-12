#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+ 5;
long long a[N], len;
long long s[N];
int vis[N];
int main() {
	long long n;
	long long x, m;
	cin >> n >> x >> m;
	a[1] = x;
	vis[x] = true;
	long long ans = 0;
	len = 1;
	while(!vis[a[len] * a[len] % m]) {
		len ++;
		a[len] = a[len - 1] * a[len - 1] % m;
		vis[a[len]] = len;
	}
	long long pos = 0;
	for (int i = vis[a[len] * a[len] % m]; i <= len; i ++) {
		pos ++;
		s[pos] = s[pos - 1] + a[i];
	}
	if (n < vis[a[len] * a[len] % m]) {
		for (int i = 1; i <= n; i ++) ans += a[i];
		cout << ans << endl;
		return 0;
	}
	n -= vis[a[len] * a[len] % m] - 1;
	for (int i = 1; i <= vis[a[len] * a[len] % m] - 1; i ++) ans += a[i];
	ans += s[pos] * (n / pos) + s[n % pos];
	cout << ans << endl;
	return 0;
}