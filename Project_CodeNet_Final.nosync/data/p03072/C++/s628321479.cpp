#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0, hmx = 0;

	int N;
	cin >> N;

	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H.at(i);
		if (H.at(i) >= hmx) {
			ans++;
			hmx = max(H.at(i), hmx);
		}
	}

	cout << ans << endl;
	return 0;
}
