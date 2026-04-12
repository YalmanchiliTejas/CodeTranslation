#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long n,k;
	cin >> n >> k;

	long long ans = 0;
	long long m;
	if (k == 0) ans = n*n;
	else {
		for (long long i = k+1;i <= n;i++){
			ans += n/i*(i-k);
			m = (n-(i*(n/i))) - k+1;
			if (m >= 0) ans += m;
		}
	}
	cout << ans << endl;

	return 0;

}
