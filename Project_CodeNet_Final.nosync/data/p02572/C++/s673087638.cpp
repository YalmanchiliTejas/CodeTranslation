#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	long long sum = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		sum += a[i];
		sum %= 1000000007;
	}

	long long ans = 0;
	for (int i = 0;i < n;i++) {
		sum -= a[i];
		if (sum <= 0) {
			sum += 1000000007;
		}
		ans += a[i] * sum;
		ans %= 1000000007;
	}

	if (ans < 0) {
		ans += 1000000007;
	}
	cout << ans << endl;

	return 0;
}
