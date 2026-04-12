#include "bits/stdc++.h"
using namespace std;

long long N, X, S, P = 0;

long long DFS(long long n, long long x) {
	if (n == 0) {
		if (x > 0) return 1;
		else return 0;
	}
	if (x <= 2 * pow(2, n) - 2) return DFS(n - 1, x - 1);
	return pow(2, n) + DFS(n - 1, x + 1 - 2 * pow(2, n));
}

int main() {
	cin >> N >> X;
	cout << DFS(N, X);
}