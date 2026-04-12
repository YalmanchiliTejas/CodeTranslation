#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	long long n, a[100000], b[100000];
	long long ans = 0;
	long long ans2=0;
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort (b, b + n);
	long long c[100000];
	int m;
	m = n;
	if (m % 2 == 0) m = m - 1;
	long long e[4];
	int p, q, r, s;
	p = -1; q = 0; r = n - 1; s = n - 2;
	e[0] = b[0];
	e[1] = b[0];
	e[2] = b[n - 1];
	e[3] = b[n - 2];
	for (i = 1; i <= (m - 1) / 2; i++) {
		long long pre1, pre2;
		pre1 = e[2] - e[0];
		pre2 = e[3] - e[1];
		if (pre1 < 0) pre1 = -pre1;
		if (pre2 < 0) pre2 = -pre2;
		ans = ans + pre1 + pre2;
		if (i % 2 == 1) {
			p = p + 2;
			q = q + 2;
			e[0] = b[p];
			e[1] = b[q];
		}
		else {
			r = r - 2;
			s = s - 2;
			e[2] = b[r];
			e[3] = b[s];
		}
	}
	if (n % 2 == 0) {
			long long u;
			u = e[2] - e[0];
			if (u < 0) u = -u;
			ans = ans + u;
	}


	p = 0; q = 1; r = n ; s = n - 1;
	e[0] = b[0];
	e[1] = b[1];
	e[2] = b[n - 1];
	e[3] = b[n - 1];
	for (i = 1; i <= (m - 1) / 2; i++) {
		long long pre1, pre2;
		pre1 = e[2] - e[0];
		pre2 = e[3] - e[1];
		if (pre1 < 0) pre1 = -pre1;
		if (pre2 < 0) pre2 = -pre2;
		ans2 = ans2 + pre1 + pre2;
		if (i % 2 == 0) {
			p = p + 2;
			q = q + 2;
			e[0] = b[p];
			e[1] = b[q];
		}
		else {
			r = r - 2;
			s = s - 2;
			e[2] = b[r];
			e[3] = b[s];
		}
	}
	if (n % 2 == 0) {
		long long u;
		u = e[2] - e[0];
		if (u < 0) u = -u;
		ans2 = ans2 + u;
	}



	if (ans2 > ans)ans = ans2;



	cout << ans << endl;
	return 0;
}