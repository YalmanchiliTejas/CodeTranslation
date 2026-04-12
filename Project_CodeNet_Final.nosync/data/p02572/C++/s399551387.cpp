// Problem Code: abc177_c

#include <bits/stdc++.h>

using namespace std;

int C(int N, vector<int>& A) {
	const int mod = 1e9 + 7;
	long long sum = 0;
	vector<long long> prefix(N + 1);
	
	for (int i = 0; i < N; i++)
		prefix[i + 1] = (prefix[i] + A[i]);
	
	for (int i = 0; i < N - 1; i++) {
		sum += (long long) A[i] * ((prefix[N] - prefix[i + 1]) % mod);
		sum %= mod;
	}
	
	return sum % mod;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << C(N, A);
	return 0;
}