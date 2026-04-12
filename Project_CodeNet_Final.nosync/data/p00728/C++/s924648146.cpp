#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		if (N == 0) break;
		int A, COUNT = 0, MAX = 0, MIN = 10000;
		for (int i = 0; i < N; i++) {
			cin >> A;
			COUNT += A;
			MAX = max(MAX, A);
			MIN = min(MIN, A);
		}
		cout << (COUNT - MAX - MIN) / (N - 2) << endl;
	}
}
