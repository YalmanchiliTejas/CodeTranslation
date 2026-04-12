#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	ll a[50];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 0;
	ll k = 0;
	do {
		if (a[r] >= n) {
			ll t = a[r] / n;
			a[r] -= t * n;
			for (int i = 0; i < n; i++) {
				if (i != r) {
					a[i] += t;
				}
			}
			k += t;
			l = r;
		}
		r = (r + 1) % n;
	} while (l != r);
	cout << k << endl;
	return 0;
}
