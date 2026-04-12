#include <bits/stdc++.h>
using namespace std;

using lint = long long;

lint mod, N, X, L, R, arr[100004], rec[100004];

int main() {
	cin >> N >> X >> mod;

	arr[1] = X;
	rec[X] = 1;

	for (int i=2; ; i++) {
		arr[i] = (arr[i-1] * arr[i-1]) % mod;
		if (rec[arr[i]]) {
			L = rec[arr[i]];
			R = i;
			break;
		}
		rec[arr[i]] = i;
	}

	lint ans = 0;

	for (int i=1; i<=N and i<R; i++) {
		if (i < L) ans += arr[i];
		else ans += arr[i] * (long long)((N-L) / (R-L) + ((N-L) % (R-L) >= i-L));
	}

	cout << ans << '\n';
}