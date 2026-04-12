#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto& x : A) cin >> x;

	vector<int> b(N);
	if (N % 2 == 0) {
		for (int i = 0; i < N; i += 2) {
			b[N/2 + i/2] = A[i];
		}
		for (int i = 1; i < N; i += 2) {
			b[N/2-1 - i/2] = A[i];
		}
	} else {
		for (int i = 0; i < N; i += 2) {
			b[N/2 - i/2] = A[i];
		}
		for (int i = 1; i < N; i += 2) {
			b[N/2+1 + i/2] = A[i];
		}
	}

	for (int i = 0; i < N; ++ i) {
		if (i) cout << " ";
		cout << b[i];
	}
	cout << endl;
}
