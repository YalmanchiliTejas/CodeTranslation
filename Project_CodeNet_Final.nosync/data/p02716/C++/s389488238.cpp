#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int n,n2;
long *a;
long ans = LONG_MIN;
long *tmp[3];

void solve(int ii, int nn2,long now,int tobasi) {
	if (ii >= n) {
		return;
	}
	if (tmp[tobasi][ii] >= now) {
		return;
	}
	tmp[tobasi][ii] = now;
	if (nn2 == n2) {
		ans = max(ans, now);
		return;
	}
	if (tobasi == 2) {
		solve(ii + 2, nn2 + 1, now + a[ii + 2], tobasi);
		if (a[ii + 3] > a[ii + 2]) {
			solve(ii + 3, nn2 + 1, now + a[ii + 3], tobasi - 1);
		}
		if (a[ii + 4] > a[ii + 3] && a[ii + 4] > a[ii + 2]) {
			solve(ii + 4, nn2 + 1, now + a[ii + 4], tobasi - 2);
		}
	}else if (tobasi == 1) {
		solve(ii + 2, nn2 + 1, now + a[ii + 2], tobasi);
		if (a[ii + 3] > a[ii + 2]) {
			solve(ii + 3, nn2 + 1, now + a[ii + 3], tobasi - 1);
		}
	}
	else {
		solve(ii + 2, nn2 + 1, now + a[ii + 2], tobasi);
	}


	return;
}

int main()
{
	int i;
	cin >> n;
	a = new long[n];
	tmp[0] = new long[n];
	tmp[1] = new long[n];
	tmp[2] = new long[n];
	for (i = 0; i < n; i++) {
		cin >> a[i];
		tmp[0][i] = LONG_MIN;
		tmp[1][i] = LONG_MIN;
		tmp[2][i] = LONG_MIN;
	}
	n2 = n / 2;


	int imax;
	if (i % 2 == 1) {
		imax = 2;
	}
	else {
		imax = 1;
	}
	for (i = 0; i <= imax; i++) {
		solve(i, 1, a[i],imax-i);
	}
	cout << ans << endl;

	return 0;
}
