#include <bits/stdc++.h>
using namespace std;

int main() {
	//input
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = N - 1; i >= 0; i--) {
		cin >> A[i];
	}

	//calculation
	int64_t output = 0;
	int64_t sum = A[0];
	for (int i = 1; i < N; i++) {
		output += sum * A[i];
		if (output >= 1000000000 + 7) {
			output %= 1000000000 + 7;
		}
		sum += A[i];
		if (sum >= 1000000000 + 7) {
			sum -= 1000000000 + 7;
		}
	}

	//output
	cout << output << endl;


	return 0;
}
