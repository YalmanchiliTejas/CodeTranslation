#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	int n;
	cin >> n;
	vector<long long> A(n), S(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		S[i] = mod(S[i] + A[i]);
		S[i+1] = mod(S[i+1] + S[i]);
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans = mod(ans + A[i] * S[i-1] % MOD);
	}
	cout << ans << endl;
	return 0;
}