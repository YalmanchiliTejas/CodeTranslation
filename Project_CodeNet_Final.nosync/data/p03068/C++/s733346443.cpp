#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	int N, K;
	char C;
	cin >> N >> S >> K;
	C = S[K - 1];
	for (int i = 0; i < N; i++) {
		if (S[i] == C) cout << C;
		else cout << '*';
	}
}