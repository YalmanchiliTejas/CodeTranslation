#include<vector>
#include<iostream>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;

	int MOD = 1000000007;
	ll sum = 0;
	vector<ll>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
		sum %= MOD;
	}

	ll ans = 0;

	for (int i = 0; i < N; i++) {
		sum -= A[i];
		if (sum < 0) sum += MOD;

		ans += A[i] * sum;
		ans %= MOD;
	}

	cout << ans << endl;

}