#include "bits/stdc++.h"
using namespace std;

int main() {
	static int N, X, A[200000], B[200000];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		A[i] = X, B[i] = X;
	}
	sort(B, B + N);
	int median = B[N / 2];
	for (int i = 0; i < N; i++) {
		if (A[i] < median) cout << median;
		else cout << B[N / 2 - 1];
		cout << endl;
	}
}