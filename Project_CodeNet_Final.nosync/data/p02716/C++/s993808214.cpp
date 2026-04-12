#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main() {
	int N; cin >> N;
	int n = N / 2;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	vector<ll> acc(N + 1, 0);
	acc[1] = A[0];
	for (int i = 2; i <= N; ++i)
		acc[i] = acc[i - 2] + A[i - 1];

	ll res = 0;

	// A1 A3 A5 ...
	for (int i = 0; i <= 2 * n - 2; i += 2)
		res += A[i];

	// A2 A4 A6 ....
	ll tmp = 0;
	for (int i = 1; i < N; i += 2)
		tmp += A[i];

	res = max(tmp, res);

	if (N % 2) {
		// A3 A5 A7 ...
		tmp = 0;
		for (int i = 2; i < N; i += 2)
			tmp += A[i];
		res = max(res, tmp);
	}

	// A1 A3 ... A[2i-1],  A[j] A[j+2] ... A[j + (n-i-1) * 2]
	for (int i = 1; i < n; ++i) {
		tmp = acc[2 * i - 1];
		ll additional = -(1LL << 60);
		for (int j = 2 * i + 2; j <= N - 2 * n + 2 * i + 2; ++j) {
			ll add = acc[j + (n - i - 1) * 2] - (j >= 2 ? acc[j - 2] : 0);
			additional = max(additional, add);
		}
		tmp += additional;
		res = max(res, tmp);
	}

	// A2 A4 ... A[2i], A[j] A[j + 2] ... A[j + (n-i-1) * 2]
	for (int i = 1; i < n; ++i) {
		tmp = acc[2 * i];
		ll additional = -(1LL << 60);
		for (int j = 2 * i + 3; j <= N - 2 * n + 2 * i + 2; ++j) {
			ll add = acc[j + (n - i - 1) * 2] - (j >= 2 ? acc[j - 2] : 0);
			additional = max(additional, add);
		}
		tmp += additional;
		res = max(res, tmp);
	}

	if (N % 2) {
		vector<vector<ll>> dp(N, vector<ll>(3, 0));
		dp[0][0] = A[0];
		dp[0][2] = A[0];
		dp[1][0] = A[0];
		dp[1][1] = A[1];
		dp[1][2] = A[0];
		for (int i = 2; i < N; ++i) {
			// そのまま継続
			for (int j = 0; j < 3; ++j)
				dp[i][j] = dp[i - 1][j];
			if (i % 2) {
				dp[i][1] += A[i];
			}
			else {
				dp[i][0] += A[i];
				dp[i][2] += A[i];
			}
			if (i % 2) {
				// 0 -> 1移行
				if (i >= 3) {
					tmp = dp[i - 3][0] + A[i];
					dp[i][1] = max(dp[i][1], tmp);
				}
			}
			else {
				// 1 -> 2移行
				if (i >= 3) {
					tmp = dp[i - 3][1] + A[i];
					dp[i][2] = max(dp[i][2], tmp);
				}
			}
		}
		tmp = max({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
		res = max(tmp, res);
	}

	cout << res << endl;
	return 0;
}
