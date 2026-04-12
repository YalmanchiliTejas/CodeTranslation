#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K, ans = 0;
	cin >> N >> K;
	if (K == 0) ans = N * N;
	else {
		for (int i = K + 1; i <= N; i++) {
			if (N % i < K) {
				ans += (i - K) * (N / i);
			}
			else {
				ans += (i - K) * (N / i) + (N % i - K + 1);
			}
		}
	}
	cout << ans;
}