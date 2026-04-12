#include <bits/stdc++.h>
using namespace std;
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	int N,sea=1,MAXX;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N;i++) {
		cin >> H.at(i);
	}
	MAXX = H.at(0);
	for (int i = 1; i < N; i++) {
		if (MAXX <= H.at(i)) {
			sea++;
		}
		MAXX = max(H.at(i), MAXX);
	}

	cout << sea << endl;
}