#include<iostream>
#include<algorithm>

using namespace std;

int A[100001];
int B[100001];
int main()
{
	int N;
	long long sum = 0;
	long long sum2 = 0;

	cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];

	sort(A, A + N);

	if (N % 2 == 0) {
		for (int i = 0; i < N; ++i) {
			if (i < (N / 2 - 1)) {
				B[i] = -2;
			}
			else {
				if (i == N / 2 - 1) {
					B[i] = -1;
				}
				else {
					if (i == N / 2) {
						B[i] = 1;
					}
					else {
						B[i] = 2;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (i < ((N - 1) / 2 - 1)) {
				B[i] = -2;
			}
			else {
				if (i == (N - 1) / 2 - 1) {
					B[i] = -1;
				}
				else {
					if (i == (N - 1) / 2) {
						B[i] = -1;
					}
					else {
						B[i] = 2;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		sum = sum + A[i] * B[i];
	}

	if (N % 2 == 0) {
		for (int i = 0; i < N; ++i) {
			if (i < (N / 2 - 1)) {
				B[i] = -2;
			}
			else {
				if (i == N / 2 - 1) {
					B[i] = -1;
				}
				else {
					if (i == N / 2) {
						B[i] = 1;
					}
					else {
						B[i] = 2;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (i < ((N - 1) / 2 )) {
				B[i] = -2;
			}
			else {
				if (i == (N - 1) / 2) {
					B[i] = 1;
				}
				else {
					if (i == (N - 1) / 2+1) {
						B[i] = 1;
					}
					else {
						B[i] = 2;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		sum2 = sum2 + A[i] * B[i];
	}

	cout << max(sum,sum2) << endl;
	return 0;

}