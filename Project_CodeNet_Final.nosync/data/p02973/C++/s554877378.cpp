#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	static long long A[100000];
	set<long long> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] = A[i] * 1000000 + 500000 - i;
	}
	S.insert(-1);
	for (int i = 0; i < N; i++) {
		if (*S.begin() >= A[i]) S.insert(A[i]);
		else {
			auto it = S.lower_bound(A[i]);
			it--;
			S.erase(*it);
			S.insert(A[i]);
		}
	}
	cout << S.size() << endl;
}