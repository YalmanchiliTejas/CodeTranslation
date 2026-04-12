#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using ll = long long;

using namespace std;

ll gcd(ll C, ll D) {
	if (C < D) gcd(D, C);

	if (C%D == 0)return D;
	else return gcd(D, C%D);
}

const int MOD = 1000000007;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	ll sum = 0;
	rep(i, N) {
		cin >> A[i];
		sum += A[i];
		sum %= MOD;
	}
	ll ans = 0;

	rep(i, N) {
		sum -= A[i];
		if (sum < 0) sum += MOD;
		ans += A[i] * sum;
		ans %= MOD;
	}

	cout << ans << endl;
	return 0;
}




