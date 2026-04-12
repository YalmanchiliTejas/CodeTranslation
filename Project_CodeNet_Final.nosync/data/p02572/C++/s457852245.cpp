#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> a(N, 0);
	vector<long long> sum(N, 0);
	long long mod = 1000000007;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (i == 0) {
			sum[0] = a[i];
		}
		else {
			sum[i] = (sum[i - 1] + a[i])%mod;
		}
	}
	long long res = 0;
	for (int i = N - 1; i >= 1; i--) {
		long long t = sum[i - 1] * a[i];
		res = (res + (sum[i - 1] * a[i]) % mod)%mod;
	}
	cout << res << endl;
	return 0;
}