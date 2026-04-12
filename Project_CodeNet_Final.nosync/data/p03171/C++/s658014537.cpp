#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

int main() {
	int n; scanf ("%d", &n);
	vector < int > a (n);
	for (int & x : a) scanf ("%d", &x);
	vector < vector < ll > > dp (n, vector < ll > (n));
	for (int L = n - 1; L >= 0; L--) {
		for (int R = L; R < n; R++) {
			if (L == R) {
				dp[L][R] = a[L];
			} else {
				dp[L][R] = max ((ll) a[L] - dp[L + 1][R], (ll)a[R] - dp[L][R - 1]);
			}
		}
	}
	printf ("%lld\n", dp[0][n - 1]);
	return 0;
}

