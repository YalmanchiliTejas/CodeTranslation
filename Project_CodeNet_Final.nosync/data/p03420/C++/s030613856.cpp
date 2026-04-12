#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	long long res = 0;
	for (int i = k + 1; i <= n; ++i) {
		res += (n / i) * (i - k);
		int rem = n % i;
		if (rem >= k) {
			res += rem - k + (k > 0);
		}
	}
	cout << res << '\n';
}