#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = (int) 2e5 + 7;
const long long MOD = (long long) 1e9 + 7ll;

int n;
long long a[N], p[N];

void add(long long &ans, long long val) {
	ans = (ans + val) % MOD;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == 0) {
			p[i] = a[0] % MOD;
		} else {
			p[i] = (p[i - 1] + a[i]);
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		add(ans, (a[i] * ((p[n - 1] - p[i]) % MOD)) % MOD);
	}
	cout << ans;
}