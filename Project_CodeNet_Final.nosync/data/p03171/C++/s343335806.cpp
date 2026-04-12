#include "bits/stdc++.h"
using namespace std;

long long N, A[3000];
static long long DP[3000][3000] = {};
bool used[3000][3000] = {};

long long DFS(long long L, long long R) {
	if (L == R) {
		return (N % 2 == 0 ? -A[L] : A[L]);
	}
	if (used[L][R]) return DP[L][R];
	long long RET;
	if ((R - L + 1) % 2 == N % 2) RET = max(DFS(L + 1, R) + A[L], DFS(L, R - 1) + A[R]);
	else RET = min(DFS(L + 1, R) - A[L], DFS(L, R - 1) - A[R]);
	used[L][R] = true;
	return DP[L][R] = RET;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << DFS(0, N - 1) << endl;
}