#include <bits/stdc++.h>

using namespace std;

int main() {
	long n, s, a, ans, j, m = 998244353, d[3001] = {};
	cin >> n >> s;
	while (n--) {
		cin >> a;
		for (j = s; j >= a; j--)
			d[j] = (d[j] + d[j - a]) % m;
		d[a]++;
		d[0]++;
		ans += d[s];
	}
	cout << ans % m << endl;
	return 0;
}