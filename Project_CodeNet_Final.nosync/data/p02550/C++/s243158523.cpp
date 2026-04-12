// E - Sequence Sum
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	long long n, x, m, c = 0, l = 0;
	cin >> n >> x >> m;
	long long ans = 0;
	map<long long, int> s;
	for (c = 0; c < n; c++) {
		if (s.count(x) > 0) {
			l = c - s[x];
			break;
		}
		ans += x;
		s[x] = c;
		x = (x * x) % m;
	}

	long long z = 0;
	for (long long t = x, i = 0; i < l; i++, t = (t * t) % m) z += t;

	if (l > 0) {
		ans += (n - c) / l * z;
		for (long long i = 0, t = x; i < (n - c) % l; i++, t = (t * t) % m)
			ans += t;
	}

	cout << ans << endl;

	return 0;
}
