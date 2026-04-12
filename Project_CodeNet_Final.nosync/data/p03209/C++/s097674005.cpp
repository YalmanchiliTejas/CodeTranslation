#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N, X;
	cin >> N >> X;
	vector<long long>P(N+1);
	vector<long long>B(N+1); 
	vector<long long>S(N + 1);
	P[0] = 1;
	B[0] = 0;
	S[0] = 1;
	for (int n = 0;n<N;++n) {
		P[n + 1] = P[n] * 2 + 1;
		B[n + 1] = B[n] * 2 + 2;
		S[n + 1] = S[n] * 2 + 3;
	}
	long long ans = 0;
	for (int n = N;n>=0;--n) {
		if (X >= 1) {
			X--;
		}
		else {
			continue;
		}
		if (X>=S[n-1]) {
			X -= S[n - 1];
			ans += P[n - 1];
		}
		else {
			continue;
		}
		if (X>=1) {
			X--;
			ans++;
		}
		else {
			continue;
		}

		if (X >= S[n - 1]) {
			X -= S[n - 1];
			ans += P[n - 1];
		}
		else {
			continue;
		}

		if (X >= 1) {
			X--;
		}
		else {
			continue;
		}
	}
	cout << ans <<endl;
	return 0;
}
