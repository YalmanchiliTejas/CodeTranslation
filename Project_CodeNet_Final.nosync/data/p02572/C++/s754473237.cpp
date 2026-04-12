// Problem Code: abc177_c

#include <iostream>
#include <vector>

using namespace std;

int get_sum(int N, vector<int>& A) {
	int mod, sum, inner_sum;
	mod = 1e9 + 7;
	sum = inner_sum = 0;
	
	for (int i = 0; i < N; i++)
		inner_sum = (inner_sum + A[i]) % mod;
	
	for (int i = 0; i < N; i++) {
		inner_sum = (inner_sum - A[i] + mod) % mod;
		sum = (sum + (long long) inner_sum * A[i]) % mod;
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