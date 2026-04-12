#include<iostream>
#include<vector>
using namespace std;

int const mod = 1000000007;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);

	int x = 0;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		ans += (long long)x * A[i] % mod;
		x = (x + A[i]) % mod;
	}

	ans %= mod;
	cout << ans << endl;
	return 0;
}