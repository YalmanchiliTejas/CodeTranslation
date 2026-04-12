#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, H[100009], dp[109][109], mod = 1000000007; vector<pair<int, int>>vec[100009];

long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];
	H[0] = 1; H[N + 1] = 1;
	for (int i = 1; i <= N; i++) {
		long long minx = (1LL << 60);
		for (int j = i; j <= N; j++) {
			minx = min(minx, H[j]);
			if (H[i - 1] < minx && minx > H[j + 1]) vec[j].push_back(make_pair(i, minx - max(H[i - 1], H[j + 1])));
		}
	}
	dp[0][1] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			long long K = 0; for (int k = 0; k < vec[i + 1].size(); k++) { if (vec[i + 1][k].first >= j) K += vec[i + 1][k].second; }
			long long L = modpow(2, K, mod);
			dp[i + 1][j] += dp[i][j] * L; dp[i + 1][j] %= mod;
			long long K1 = 0; for (int k = 0; k < vec[i + 1].size(); k++) { if (vec[i + 1][k].first >= i + 1) { K1 += vec[i + 1][k].second; } }
			long long L1 = modpow(2, K1, mod);
			dp[i + 1][i + 1] += dp[i][j] * L1; dp[i + 1][i + 1] %= mod;
		}
	}
	long long sum = 0;
	for (int i = 1; i <= N; i++) sum += dp[N][i];
	cout << sum%mod << endl;
	return 0;
}