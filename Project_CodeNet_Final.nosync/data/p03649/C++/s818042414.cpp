#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, s, t, mx = -1, x, x2, a[55];
int main()
{
	ll i, j, k;
	cin >> n;
	mx = -1;
	for (i =0; i < n; i++) {
		scanf ("%lld", &a[i]);
		if (a[i] > mx) {
			mx = a[i];
			x = i;
		}
	}
	while (1) {
		t = (a[x] - n + 1) / n;
		if ((a[x] - n + 1) % n) t++;
		s += t;
		mx = -1;
		for (i = 0; i < n; i++) {
			if (i == x) a[i] -= t * n;
			else a[i] += t;
			if (a[i] > mx) {
				mx = a[i];
				x2 = i;
			}
		}
		x = x2;
		if (mx < n) break;
	}
	cout << s;
    return 0;
}
