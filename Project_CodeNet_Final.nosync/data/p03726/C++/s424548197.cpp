#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	vector<long long> X, To;
	vector<bool> B;
	vector<vector<long long> > V;
	cin >> N;
	X.assign(N, 0);
	To.assign(N, 0);
	B.assign(N, false);
	V.resize(N);
	for (int i = 0; i < N - 1; i++) {
		long long A, B;
		cin >> A >> B;
		A--, B--;
		X[A]++, X[B]++;
		To[A] += B, To[B] += A;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	queue<long long> Q;
	for (int i = 0; i < N; i++) {
		if (X[i] == 1) {
			if (B[i] || B[To[i]]) continue;
			B[i] = B[To[i]] = true;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		long long P = Q.front();
		Q.pop();
		long long NP = To[P];
		B[P] = B[NP] = true;
		for (long long NNP : V[NP]) {
			if (B[NNP]) continue;
			X[NNP]--;
			To[NNP] -= NP;
			if (X[NNP] == 1 && !B[NNP]) {
				Q.push(NNP);
			}
			if (X[NNP] == 0) {
				cout << "First" << endl;
				return 0;
			}
		}
	}
	cout << "Second" << endl;
}