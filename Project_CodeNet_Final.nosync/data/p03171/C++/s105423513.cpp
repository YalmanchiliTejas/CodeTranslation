#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;

	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	vector<vector<ll>> dp(N, vector<ll>(N));
	for (int L = N - 1; L >= 0; --L) {
		for (int R = L; R < N; ++R) {
			if (L == R)
				dp[L][R] = a[L];
			else
				dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
		}
	}
	
	cout << dp[0][N-1] << endl;
}
