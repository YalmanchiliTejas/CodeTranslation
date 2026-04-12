#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> A;
	A.resize(N);
	for (int n = 0; n < N; n++)cin >> A[n];
	vector<vector<long long>> DP;
	DP.resize(N, vector<long long>(N, 0));
	if ((N - 1) % 2 == 0) {
		for (int n = 0; n < N; n++)DP[n][n] = A[n];
	}
	else {
		for (int n = 0; n < N; n++)DP[n][n] = -A[n];
	}
	for (int k = 1; k < N; k++) {
		for (int l = 0; l < N; l++) {
			int r = l + k;
			if (r >= N)continue;
			if ((N - r + l - 1) % 2 == 0) {
				DP[l][r] = max(DP[l + 1][r] + A[l], DP[l][r - 1] + A[r]);
			}
			else {
				DP[l][r] = min(DP[l + 1][r] - A[l], DP[l][r - 1] - A[r]);
			}
		}
	}
	cout << DP[0][N - 1] << endl;
	return 0;
}