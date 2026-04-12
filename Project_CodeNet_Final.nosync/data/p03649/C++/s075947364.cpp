#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[50], ANS = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	while (1) {
		long long COUNT = 0;
		for (int i = 0; i < N; i++) COUNT += A[i] / N;
		if (COUNT == 0) {
			cout << ANS;
			return 0;
		}
		ANS += COUNT;
		for (int i = 0; i < N; i++) {
			A[i] = A[i] - (A[i] / N) * N + COUNT - A[i] / N;
		}
	}
}