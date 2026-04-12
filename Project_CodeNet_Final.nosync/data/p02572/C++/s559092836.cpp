#include <iostream>
#include <vector>
using namespace std;


int main()
{
	auto& in = cin;

	int N;
	in >> N;
	long long sum = 0;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) {
		in >> A[i];
		sum += A[i];
	}

	long long mod = 1000000007;
	long long result = 0;
	for (int i = 0; i < N - 1; ++i) {
		sum -= A[i];
		result += (A[i] * (sum % mod)) % mod;
		result %= mod;
	}
	cout << result % mod;

	return 0;
}
