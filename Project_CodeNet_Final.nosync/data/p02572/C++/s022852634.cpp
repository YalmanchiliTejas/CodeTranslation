#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define MOD 1000000007

typedef long long int llint;

llint N;

int main() {
	cin >> N;
	vector<llint> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	llint ans = 0;
	llint sum = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		ans += (A[i] * sum) % MOD;
		ans %= MOD;
		sum = (sum + A[i]) % MOD;
	}
	cout << ans << endl;
}