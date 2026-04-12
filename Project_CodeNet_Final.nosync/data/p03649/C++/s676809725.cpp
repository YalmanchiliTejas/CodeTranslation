#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <functional>
#include <stdlib.h>
using namespace std;
signed main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long a[53];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	sort(a, a + n, greater<int>());
	if (a[0] > 2 * n) {
		for (int i = 1; i < n; i++) {
			long long cnt = (a[0] - a[i]) / (n + 1);
			for (int j = 0; j < i; j++) {
				a[j] -= cnt*(n - (i - 1));
			}
			for (int j = i; j<n; j++) {
				a[j] += cnt*i;
			}
			ans += cnt*i;
		}
	}
	sort(a, a + n, greater<long long>());
	while (a[0] - a[n - 1]>n) {
		a[0] -= n;
		for (int i = 1; i < n; i++) {
			a[i] += 1;
		}
		ans += 1;
		sort(a, a + n, greater<long long>());
	}
	if (a[n - 1] > n - 1) {
		ans += (a[n - 1] - (n - 1))*n;
		long long tmp = a[n - 1] - (n - 1);
		for (int i = 0; i < n; i++) {
			a[i] -= tmp;
		}
	}
	while (a[0] > n - 1) {
		a[0] -= n;
		for (int i = 1; i < n; i++) {
			a[i] += 1;
		}
		ans += 1;
		sort(a, a + n, greater<long long>());
	}
	cout << ans;
	return 0;
}