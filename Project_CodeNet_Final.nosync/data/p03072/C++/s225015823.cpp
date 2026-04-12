#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> h(N);
	for (int i = 0; i < N; ++i) {
		cin >> h.at(i);
	}
	int res = 0;
	int max = h.at(0);
	for (int i = 0; i < N; i++) {
		if (h.at(i) >= max) {
			max = h.at(i);
			res++;
		}
	}
	cout << res << endl;
}