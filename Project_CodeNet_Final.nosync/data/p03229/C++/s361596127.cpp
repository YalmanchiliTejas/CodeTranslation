#include "bits/stdc++.h"
using namespace std;

int main() {
	static long long N, A[100000], B[100000], count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	if (N % 2 == 0) {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) B[i] = A[(N - i - 2) / 2];
			else B[i] = A[(N * 2 - i - 1) / 2];
		}
		for (int i = 1; i < N; i++) {
			count += abs(B[i] - B[i - 1]);
		}
	}
	else {
		long long count1 = 0, count2 = 0;
		B[0] = A[(N - 1) / 2];
		for (int i = 1; i < N; i++) {
			if (i % 2 == 0) B[i] = A[(i - 2) / 2];
			else B[i] = A[(N + i) / 2];
		}
		for (int i = 1; i < N; i++) {
			count1 += abs(B[i] - B[i - 1]);
		}
		for (int i = 1; i < N; i++) {
			if (i % 2 == 1) B[i] = A[(i - 1) / 2];
			else B[i] = A[(N * 2 - i) / 2];
		}
		for (int i = 1; i < N; i++) {
			count2 += abs(B[i] - B[i - 1]);
		}
		count = max(count1, count2);
	}
	cout << count;
}