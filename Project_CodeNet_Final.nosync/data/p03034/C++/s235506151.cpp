#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, A[1 << 18], maxn = -(1LL << 60);

long long solve(int pos) {
	if ((N - 1) % pos == 0) {
		vector<long long> E;
		for (int i = 0; i <= N - 1; i += pos) E.push_back(A[i]);

		int cl = 0, cr = E.size() - 1; long long val = 0, maxv = -(1LL << 60);
		while (cl < cr) {
			val += E[cl] + E[cr]; cl++; cr--;
			maxv = max(maxv, val);
		}
		return maxv;
	}
	else {
		long long B = (N - 1) % pos;
		vector<long long> E1, E2;
		for (int i = 0; i <= N - 1; i += pos) E1.push_back(A[i]);
		for (int i = B; i <= N - 1; i += pos) E2.push_back(A[i]);

		long long val = 0, maxv = 0;
		for (int i = 0; i < (int)E1.size() - 1; i++) val += E1[i];
		for (int i = 1; i < (int)E2.size(); i++) val += E2[i];
		maxv = val;

		for (int i = 0; i < (int)E1.size() - 1; i++) {
			val -= E1[E1.size() - 2 - i];
			val -= E2[i + 1];
			maxv = max(maxv, val);
		}
		return maxv;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i <= N - 1; i++) cin >> A[i];

	// A - B を全探索
	for (int i = 1; i <= N; i++) {
		long long val = solve(i);
		maxn = max(maxn, val);
	}
	cout << maxn << endl;
	return 0;
}