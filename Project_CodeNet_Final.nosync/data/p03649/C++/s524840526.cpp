#include <iostream>
#include <cstdio>
#define N 55
using namespace std;

typedef long long ll;
ll n, c, mx, mi, a[N];
int main()
{
	ll i, t;
	cin >> n;
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	while (1) {
		mx = mi = n;
		for (i = 0; i < n; i++) if (a[i] >= mx) mi = i, mx = a[i];
		if (mi == n) break;
		t = (a[mi] - n - 1) / n + 1;
		c += t;
		a[mi] -= t * n;
		for (i = 0; i < n; i++) if (i != mi) a[i] += t;
	}
    cout << c << endl;
    return 0;
}