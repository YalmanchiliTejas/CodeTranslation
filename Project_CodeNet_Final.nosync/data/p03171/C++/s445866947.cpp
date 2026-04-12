#include <bits/stdc++.h>

using namespace std;

void getResult(int a, int b, long long* vals, long long** result) {

	if (result[a][b] != -1) {
		return;
	}

	if (a == b) {
		result[a][b] = vals[a];
		return;
	}

	getResult(a + 1, b, vals, result);
	getResult(a, b - 1, vals, result);

	if (result[a + 1][b] < result[a][b - 1]) {
		result[a][b] = result[a + 1][b] + vals[a];
	}

	else {

	}

	result[a][b] = max(vals[a] - result[a + 1][b], vals[b] - result[a][b - 1]);
	return;

}

int main() {

	int n;
	cin >> n;

	long long vals[n];
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	// Resulting value of x-y for a game only including values from indices a to b
	long long** result = new long long*[n];
	for (int i = 0; i < n; i++) {
		result[i] = new long long[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = -1l;
		}
	}

	getResult(0, n-1, vals, result);
	cout << result[0][n-1] << endl;

}