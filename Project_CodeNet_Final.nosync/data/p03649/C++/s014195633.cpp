#include <bits/stdc++.h>

using namespace std;

const int N = 51;
long long a[N];

main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long ans = 0;
	bool ok = false;
	while (!ok) {
		for (int i = 0; i < n; i++)
			if (a[i] >= n) {
				long long x = a[i] / n;
				a[i] %= n;
				ans += x;
				for (int j = 0; j < n; j++)
					if (i - j)
						a[j] += x;
			}
		ok = true;
		for (int i = 0; i < n; i++)
			if (a[i] >= n)
				ok = false;
	}
	cout << ans << endl;
}