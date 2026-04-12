#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>H(N);
	for (int n = 0;n<N;++n) {
		cin >> H[n];
	}	
	int ans = 0;
	int high = 0;
	for (int n = 0; n < N; ++n) {
		if (high<=H[n]) {
			ans++;
			high = H[n];
		}
	}
	cout << ans << endl;
	return 0;
}