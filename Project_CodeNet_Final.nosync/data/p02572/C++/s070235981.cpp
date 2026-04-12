#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long N;
	cin >> N;
	vector<long long> A(N, 0);

	long long b = 1000000007;
	
	for (long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (N > 2) {
		vector<long long> v(N, A[N - 1]);
		for (long long i = N - 3; i > 0; i--) {
			v[i] += A[i + 1];
			v[i] %= b;
			v[i - 1] = v[i];
		}
		v[0] += A[1];
		v[0] %= b;

		long long sum = 0;
		for (long long i = 0; i < N - 1; i++) {
			sum += A[i] * v[i];
			sum %= b;
		}

		cout << sum << endl;
	}
	else {
		long long sum = 0;
		sum = A[0] * A[1];
		sum %= b;

		cout << sum << endl;
	}

	return 0;
}