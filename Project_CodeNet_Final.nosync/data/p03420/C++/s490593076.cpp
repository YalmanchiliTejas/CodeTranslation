#include <bits/stdc++.h>

using namespace std;

int main(void) {
	long long N, K;
	cin >> N >> K;
	long long result = 0;
	if(K == 0) {
		cout << N * N << '\n';
		return 0;
	}
	for(long long b = K + 1; b <= N; ++b) {
		long long n = N / b * b;
		long long ng = K * (n / b);
		ng += min((N + 1) - n, K);
		result += (N + 1) - ng;
	}
	cout << result << '\n';
	return 0;
}

