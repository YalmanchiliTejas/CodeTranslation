#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	long long INF = 1000000000000000000;
	cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	if (N % 2 == 0) {
		vector<long long> L(N / 2 + 1), R(N / 2 + 1);
		L[0] = R[N / 2] = 0;
		for (int i = 0; i < N / 2; i++) {
			L[i + 1] = L[i] + A[i * 2];
		}
		for (int i = N / 2; i > 0; i--) {
			R[i - 1] = R[i] + A[i * 2 - 1];
		}
		long long ANS = -INF;
		for (int i = 0; i <= N / 2; i++) {
			ANS = max(ANS, L[i] + R[i]);
		}
		cout << ANS << endl;
		return 0;
	}
	long long ANS = -INF;
	vector<long long> L(N / 2 + 1), R(N / 2 + 1);
	L[0] = R[N / 2] = 0;
	for (int i = 0; i < N / 2; i++) {
		L[i + 1] = L[i] + A[i * 2 + 1];
	}
	for (int i = N / 2; i > 0; i--) {
		R[i - 1] = R[i] + A[i * 2];
	}
	for (int i = 0; i <= N / 2; i++) {
		ANS = max(ANS, L[i] + R[i]);
	}
	long long COUNT = 0;
	for (int i = 0; i < N; i += 2) COUNT += A[i];
	for (int i = 0; i < N; i += 2) ANS = max(ANS, COUNT - A[i]);
	vector<vector<long long> > DP(N, vector<long long>(3, -INF));
	DP[0][0] = A[0];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (i + 2 < N) DP[i + 2][j] = max(DP[i + 2][j], DP[i][j] + A[i + 2]);
			if (i + 3 < N && j < 2) DP[i + 3][j + 1] = max(DP[i + 3][j + 1], DP[i][j] + A[i + 3]);
		}
	}
	ANS = max(ANS, DP[N - 1][1]);
	ANS = max(ANS, DP[N - 1][2]);
	cout << ANS << endl;
}