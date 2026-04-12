// Problem Code: abc177_c

#include <iostream>
#include <vector>

using namespace std;

int get_sum(int N, vector<int>& A) {
	int sum = 0, mod = 1e9 + 7;
	vector<int> prefix(N + 1);
	
	for (int i = 0; i < N; i++)
		prefix[i + 1] = (prefix[i] + A[i]) % mod;
	
	for (int i = 0; i < N - 1; i++) {
		long long inner_sum = (prefix[N] - prefix[i + 1] + mod) % mod;
		sum = (sum + A[i] * inner_sum) % mod;
	}
	
	return sum;
}

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << get_sum(N, A);
	return 0;
}