#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll N, K;
	cin >> N >> K;
	if (K == 0) {
		cout << N * N << endl;
		return 0;
	}
	ll res = 0;
	for (int i = K + 1; i <= N; i++) {
		res += (N / i * (i - K)) + max(0ll, N % i - K + 1);
	}
	cout << res << endl;
	return 0;
}
