#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;

int P[52];
int B[52];
int T[52];
int solve(int N, int X) {
	if (N == 0)return 1;
	if (X == 1)return 0;
	X--;

	if (X <= T[N - 1]) {
		return solve(N - 1, X);
	}
	X -= T[N - 1];
	
	if (X == 1)return 1 + P[N - 1];
	X--;

	if (X <= T[N - 1]) {
		return 1 + P[N - 1] + solve(N - 1, X);
	}
	X -= T[N - 1];


	return 1 + 2 * P[N - 1];
	
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	P[0] = 1;
	B[0] = 0;
	T[0] = 1;
	for (int i = 1; i < 51; i++) {
		P[i] = 2 * P[i - 1] + 1;
		B[i] = 2 * B[i - 1] + 2;
		T[i] = 2 * T[i - 1] + 3;
	}
	int N, X;
	cin >> N >> X;
	cout << solve(N, X) << endl;
}