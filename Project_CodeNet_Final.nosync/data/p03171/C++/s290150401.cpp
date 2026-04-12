//未

#include <iostream>
#include <limits>

using namespace std;

int N;
int *a;
long long **DP;

long long calc(int i, int j) {
	if (i == N - 1 - j) {
		//残り１つはどちらが取るか
		if (N % 2 == 0) return -a[i]; //次郎
		else return a[i];//太郎
	}
	else if (DP[i][j] != numeric_limits<long long>::max()) return DP[i][j];
	else {
		if ((i + j) % 2 == 0) { //太郎
			long long  max = a[i] + calc(i + 1, j);
			if (max < a[N - 1 - j] + calc(i, j + 1)) max = a[N - 1 - j] + calc(i, j + 1);
			return DP[i][j] = max;
		}
		else {
			long long min = -a[i] + calc(i + 1, j);
			if (min > -a[N - 1 - j] + calc(i, j + 1)) min = -a[N - 1 - j] + calc(i, j + 1);
			return DP[i][j] = min;
		}
	}
}

int main() {
	int i, j;

	cin >> N;

	a = new int[N];
	for (i = 0; i < N; i++)
		cin >> a[i];

	DP = new long long*[N];
	for (i = 0; i < N; i++)
		DP[i] = new long long[N];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			DP[i][j] = numeric_limits<long long>::max();
	}

	cout << calc(0, 0) << endl;

	for (i = 0; i < N; i++)
		delete[] DP[i];
	delete[] DP;
	delete[] a;


	return 0;
}